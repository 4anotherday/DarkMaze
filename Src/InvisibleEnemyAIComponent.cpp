#include "InvisibleEnemyAIComponent.h"
#include "UserComponentsIDs.h"
#include "Transform.h"
#include "Engine.h"
#include "GameObject.h"
#include "RigidBodyComponent.h"
#include <random>
#include "EngineTime.h"
#include "RayCast.h"

#define CAST_COMPONENT InvisibleEnemyAIComponent* comp = static_cast<InvisibleEnemyAIComponent*>(component);

ADD_COMPONENT(InvisibleEnemyAIComponent)

InvisibleEnemyAIComponent::InvisibleEnemyAIComponent() : Component(UserComponentId::InvisibleEnemyAIComponent),
	_rb(nullptr), _speed(3.0), _transformPlayer(nullptr), _myTransform(nullptr), _ai(nullptr), _states(), _transitions(), 
	_radiusFindPlayer(15), _minRadiusFindPlayer(4), _maxRadiusFindPlayer(20),
	_sightingDistance(19), _lastKnownPosition(), _justLostSightTime(-1.0f), _lostSightSearchTime(3.0f),
	_attackRange(2.0f)
{

}

InvisibleEnemyAIComponent::~InvisibleEnemyAIComponent()
{
	delete _ai; _ai = nullptr;
	for (State* s : _states) {
		delete s; s = nullptr;
	}
	for (Transition* t : _transitions) {
		delete t; t = nullptr;
	}
}

void InvisibleEnemyAIComponent::awake(luabridge::LuaRef& data)
{
	GameObject* player = Engine::getInstance()->findGameObject("Player");

	_rb = GETCOMPONENT(RigidBodyComponent, ComponentId::Rigidbody);

	_transformPlayer = static_cast<Transform*>(player->getComponent(ComponentId::Transform));
	_myTransform = GETCOMPONENT(Transform, ComponentId::Transform);

	createFSM(data);
}

void InvisibleEnemyAIComponent::update()
{
	_ai->step();
}

void InvisibleEnemyAIComponent::moveTowardsPos(const Vector3& pos)
{
	Vector3 dir = _myTransform->getPosition() - pos;
	if (dir.magnitude() < 0.2)
		return;
	dir = dir.normalize();
	dir = dir * _speed;
	_rb->addForce(dir);
}

inline void InvisibleEnemyAIComponent::justLostSight()
{
	_justLostSightTime = _lostSightSearchTime;
	_lastKnownPosition = _transformPlayer->getPosition();
}

void InvisibleEnemyAIComponent::createFSM(luabridge::LuaRef& data)
{
	_ai = new FSM(this);

	FindState* find = createState<FindState>(); 
	find->setFindRadius(&_radiusFindPlayer);
	find->setJustLostTime(&_justLostSightTime);

	State* towardsPlayer = createState<GoTowardsPlayerState>();
	State* attackPlayer = createState<AttackPlayerState>();
	State* towardsSound = createState<TowardsSoundState>();

	LostSightTransition* lostSightTransition = createTransition<LostSightTransition>();
	lostSightTransition->setSightingDistance(&_sightingDistance);

	GainSightTransition* gainSightTransition = createTransition<GainSightTransition>();
	gainSightTransition->setSightingDistance(&_sightingDistance);

	InRangeTransition* inRangeTransition = createTransition<InRangeTransition>();
	inRangeTransition->setRange(_attackRange);

	Transition* loudSoundTransition = createTransition<LoudSoundTransition>();
	Transition* noSoundTransition = createTransition<NoSoundTransition>();

	_ai->add(find, gainSightTransition, towardsPlayer);
	_ai->add(find, loudSoundTransition, towardsSound);

	_ai->add(towardsPlayer, lostSightTransition, find);
	_ai->add(towardsPlayer, inRangeTransition, attackPlayer);

	_ai->add(towardsSound, noSoundTransition, find);
	_ai->add(towardsSound, gainSightTransition, towardsPlayer);

	_ai->add(attackPlayer, lostSightTransition, find);

	_ai->setInitialState(find);
}

template<typename T>
T* InvisibleEnemyAIComponent::createState()
{
	T* state = new T();
	_states.push_back(state);
	return state;
}

template<typename T>
T* InvisibleEnemyAIComponent::createTransition()
{
	T* transition = new T();
	_transitions.push_back(transition);
	return transition;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
//-------------  STATES    STATES    STATES    STATES    STATES    STATES    STATES    STATES    STATES    STATES    STATES    STATES  -------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------

void InvisibleEnemyAIComponent::FindState::execute(Component* component)
{
	CAST_COMPONENT;

	comp->updateRadiusFind(EngineTime::getInstance()->deltaTime());

	if (*_justLostTime > 0) {
		_targetPos = comp->getLastKnownPosition();
		*_justLostTime -= EngineTime::getInstance()->deltaTime();
	}

	double distance = (comp->getMyTransform()->getPosition() - _targetPos).magnitude();

	//If I arrived to destination, I change it
	if (distance < 2) {
		Vector3 dirVector = Vector3(-1.0 + 2.0 * ((float)rand()) / RAND_MAX, -1.0 + 2.0 * ((float)rand()) / RAND_MAX, -1.0 + 2.0 * ((float)rand()) / RAND_MAX).normalize();
		_targetPos = comp->getPlayerTransform()->getPosition() + (dirVector * *_radiusFromPlayer);
	}
	comp->moveTowardsPos(_targetPos);
}

void InvisibleEnemyAIComponent::GoTowardsPlayerState::execute(Component* component)
{
	CAST_COMPONENT;

	comp->moveTowardsPos(comp->getPlayerTransform()->getPosition());
}


void InvisibleEnemyAIComponent::AttackPlayerState::execute(Component* component)
{
	CAST_COMPONENT;

	double distance = (comp->getMyTransform()->getPosition() - comp->getPlayerTransform()->getPosition()).magnitude();
	if (distance < 1) {
		//TODO: Atacar
	}
}


void InvisibleEnemyAIComponent::TowardsSoundState::execute(Component* component)
{
	CAST_COMPONENT;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------
//-------------  TRANSITIONS     TRANSITIONS    TRANSITIONS    TRANSITIONS    TRANSITIONS    TRANSITIONS    TRANSITIONS    TRANSITIONS  -------------
//---------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------

bool InvisibleEnemyAIComponent::LostSightTransition::evaluate(Component* component)
{
	CAST_COMPONENT;

	const Vector3& playerPos = comp->getPlayerTransform()->getPosition();
	const Vector3& myPos = comp->getMyTransform()->getPosition();

	//If ray doesnt hit anything static, that means we have direct sight towards the player
	RayCast::RayCastHit ray = RayCast(myPos, playerPos, RayCast::Type::Static).getRayCastInformation();
	if (ray.hit || (playerPos - myPos).magnitude() > *_sightingDistance) {
		comp->justLostSight();
		return true;
	}

	return false;
}

bool InvisibleEnemyAIComponent::GainSightTransition::evaluate(Component* component)
{
	CAST_COMPONENT;
	
	const Vector3& playerPos = comp->getPlayerTransform()->getPosition();
	const Vector3& myPos = comp->getMyTransform()->getPosition();

	//If ray doesnt hit anything static, that means we have direct sight towards the player
	RayCast::RayCastHit ray = RayCast(myPos, playerPos, RayCast::Type::Static).getRayCastInformation();
	if (!ray.hit && (playerPos - myPos).magnitude() < *_sightingDistance) {
		comp->setFindRadius(0.0);
		return true;
	}

	return false;
}

bool InvisibleEnemyAIComponent::LoudSoundTransition::evaluate(Component* component)
{
	CAST_COMPONENT;
	return false;
}


bool InvisibleEnemyAIComponent::NoSoundTransition::evaluate(Component* component)
{
	CAST_COMPONENT;
	return false;
}

bool InvisibleEnemyAIComponent::InRangeTransition::evaluate(Component* component)
{
	CAST_COMPONENT;

	const Vector3& playerPos = comp->getPlayerTransform()->getPosition();
	const Vector3& myPos = comp->getMyTransform()->getPosition();

	return (playerPos - myPos).magnitude() < _attackRange;
}
