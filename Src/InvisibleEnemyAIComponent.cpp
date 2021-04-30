#include "InvisibleEnemyAIComponent.h"
#include "UserComponentsIDs.h"
#include "Transform.h"
#include "Engine.h"
#include "GameObject.h"
#include "RigidBodyComponent.h"
#include <random>
#include "EngineTime.h"

#define CAST_COMPONENT InvisibleEnemyAIComponent* comp = static_cast<InvisibleEnemyAIComponent*>(component);

ADD_COMPONENT(InvisibleEnemyAIComponent)

InvisibleEnemyAIComponent::InvisibleEnemyAIComponent() : Component(UserComponentId::InvisibleEnemyAIComponent),
	_transformPlayer(nullptr), _ai(nullptr), _states(), _transitions(), _radiusFindPlayer(15), _minRadiusFindPlayer(4), _maxRadiusFindPlayer(20)
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

	_transformPlayer = GETCOMPONENT(Transform, ComponentId::Transform);

	createFSM(data);
}

void InvisibleEnemyAIComponent::update()
{
	_ai->step();
}

void InvisibleEnemyAIComponent::createFSM(luabridge::LuaRef& data)
{
	_ai = new FSM(this);

	FindState* find = createState<FindState>(); 
	find->setRadius(&_radiusFindPlayer);
	State* towardsPlayer = createState<GoTowardsPlayerState>();
	State* attackPlayer = createState<AttackPlayerState>();
	State* towardsSound = createState<TowardsSoundState>();

	Transition* lostSightTransition = createTransition<LostSightTransition>();
	Transition* gainSightTransition = createTransition<GainSightTransition>();
	Transition* inRangeTransition = createTransition<InRangeTransition>();
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

	comp->updateRadiusFind(0.1 * EngineTime::getInstance()->deltaTime());

	double distance = (comp->getMyTransform()->getPosition() - _targetPos).magnitude();
	if (distance < 2) {
		findNewTargetPos(comp->getPlayerTransform()->getPosition());
	}
	moveToTargetPos();
}

void InvisibleEnemyAIComponent::FindState::findNewTargetPos(const Vector3& playerPos)
{
	Vector3 dirVector = Vector3(-1 + 2 * ((float)rand()) / RAND_MAX, -1 + 2 * ((float)rand()) / RAND_MAX, -1 + 2 * ((float)rand()) / RAND_MAX).normalize();
	_targetPos = playerPos + (dirVector * *_radiusFromPlayer);
}

void InvisibleEnemyAIComponent::FindState::moveToTargetPos()
{
	//TODO: Moverse hacia _targetPos
}

void InvisibleEnemyAIComponent::GoTowardsPlayerState::execute(Component* component)
{
	CAST_COMPONENT;
	const Vector3& targetPos = comp->getPlayerTransform()->getPosition();


	//TODO: Moverse hacia targetPos
}

void InvisibleEnemyAIComponent::AttackPlayerState::execute(Component* component)
{
	CAST_COMPONENT;

	double distance = (comp->getMyTransform()->getPosition() - comp->getPlayerTransform()->getPosition()).magnitude();
	if (distance < 2) {
		//TODO: Atacar
	}
}

//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
//-------------  TRANSITIONS   TRANSITIONS  TRANSITIONS  TRANSITIONS  TRANSITIONS  TRANSITIONS  TRANSITIONS  TRANSITIONS  TRANSITIONS  -------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------

bool InvisibleEnemyAIComponent::LostSightTransition::evaluate(Component* component)
{
	CAST_COMPONENT;
	return false;
}

bool InvisibleEnemyAIComponent::GainSightTransition::evaluate(Component* component)
{
	CAST_COMPONENT;
	comp->setRadius(0.0);
	return false;
}

bool InvisibleEnemyAIComponent::LoudSoundTransition::evaluate(Component* component)
{
	CAST_COMPONENT;
	return false;
}

bool InvisibleEnemyAIComponent::InRangeTransition::evaluate(Component* component)
{
	CAST_COMPONENT;
	return false;
}

void InvisibleEnemyAIComponent::TowardsSoundState::execute(Component* component)
{
}

bool InvisibleEnemyAIComponent::NoSoundTransition::evaluate(Component* component)
{
	return false;
}
