#include "InvisibleEnemyAIComponent.h"
#include "UserComponentsIDs.h"
#include "Transform.h"
#include "Engine.h"
#include "GameObject.h"
#include <random>
#include "EngineTime.h"
#include "RayCast.h"
#include "includeLUA.h"
#include "AudioSourceComponent.h"
#include "HealthComponent.h"
#include "PlayerVisibilityComponent.h"

#define CAST_COMPONENT InvisibleEnemyAIComponent* comp = static_cast<InvisibleEnemyAIComponent*>(component);

ADD_COMPONENT(InvisibleEnemyAIComponent)

InvisibleEnemyAIComponent::InvisibleEnemyAIComponent() : Component(UserComponentId::InvisibleEnemyAIComponent),
	_transformPlayer(nullptr), _myTransform(nullptr), _audioSource(nullptr), _playerHealth(nullptr),
	_playerVisibility(nullptr), _ai(nullptr), _states(), _transitions(),
	_actualSpeed(), _speed(3.0), _slowAfterHit(0.25),
	_radiusFindPlayer(15.0), _minRadiusFindPlayer(6.0), _maxRadiusFindPlayer(20.0),
	_sightingDistance(19.0), _lastKnownPosition(), _justLostSightTime(-1.0f), _lostSightSearchTime(3.0f),
	_attackRange(2.0f), _attackCooldown(3.0f), _attackCooldownTime(-1.0f),
	_hearingDistance(20.0), _soundLocation(), _soundTime(-1.0f), _soundTimeSearchTime(5.0f)
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
	//Speed
	if (LUAFIELDEXIST(Speed))					_speed = GETLUAFIELD(Speed, double);
	if (LUAFIELDEXIST(SlowAfterHit))			_slowAfterHit = GETLUAFIELD(SlowAfterHit, double);
	_actualSpeed = _speed;

	//Find
	if (LUAFIELDEXIST(InitialRadiusFindPlayer))	_radiusFindPlayer = GETLUAFIELD(InitialRadiusFindPlayer, double);
	if (LUAFIELDEXIST(MinRadiusFindPlayer))		_minRadiusFindPlayer = GETLUAFIELD(MinRadiusFindPlayer, double);
	if (LUAFIELDEXIST(MaxRadiusFindPlayer))		_maxRadiusFindPlayer = GETLUAFIELD(MaxRadiusFindPlayer, double);

	//Sight
	if (LUAFIELDEXIST(SightingDistance))		_sightingDistance = GETLUAFIELD(SightingDistance, double);
	if (LUAFIELDEXIST(LostSightSearchTime))		_lostSightSearchTime = GETLUAFIELD(LostSightSearchTime, float);

	//Attack
	if (LUAFIELDEXIST(AttackRange))				_attackRange = GETLUAFIELD(AttackRange, float);
	if (LUAFIELDEXIST(AttackCoolDown))			_attackCooldown = GETLUAFIELD(AttackCoolDown, float);

	//Hearing
	if (LUAFIELDEXIST(HearingDistance))			_hearingDistance = GETLUAFIELD(HearingDistance, double);
	if (LUAFIELDEXIST(SoundTimeSearchTime))		_soundTimeSearchTime = GETLUAFIELD(SoundTimeSearchTime, float);
}

void InvisibleEnemyAIComponent::start()
{
	GameObject* player = Engine::getInstance()->findGameObject("Player");

	_transformPlayer = static_cast<Transform*>(player->getComponent(ComponentId::Transform));
	_myTransform = GETCOMPONENT(Transform, ComponentId::Transform);

	_audioSource = GETCOMPONENT(AudioSourceComponent, ComponentId::AudioSource);
	_audioSource->setAudioLoop(0, -1);
	_audioSource->playAudio(0);

	_playerHealth = static_cast<HealthComponent*>(player->getComponent(UserComponentId::HealthComponent));
	_playerVisibility = static_cast<PlayerVisibilityComponent*>(player->getComponent(UserComponentId::PlayerVisibilityComponent));

	createFSM();
}

void InvisibleEnemyAIComponent::update()
{
	_ai->step();
	float deltaTime = EngineTime::getInstance()->deltaTime();
	if (_soundTime > -1.0f) _soundTime -= deltaTime;
	if (_attackCooldownTime > -1.0f) _attackCooldownTime -= deltaTime;
	if (_justLostSightTime > -1.0f) _justLostSightTime -= deltaTime;
}

void InvisibleEnemyAIComponent::moveTowardsPos(const Vector3& pos)
{
	Vector3 dir = pos - _myTransform->getPosition();
	if (dir.magnitude() < 0.2)
		return;
	dir.setY(0.0);
	dir = dir.normalize();
	dir = dir * _actualSpeed * EngineTime::getInstance()->deltaTime();
	
	_myTransform->setPosition(_myTransform->getPosition() + dir);
}

void InvisibleEnemyAIComponent::slowAfterHit(bool apply)
{
	_actualSpeed = apply ? _speed * _slowAfterHit : _speed;
}

void InvisibleEnemyAIComponent::sound(const Vector3& soundLocation, float intensity)
{
	intensity = std::min(1.0f, std::max(0.0f, intensity));

	//If I can hear the sound
	double distance = (soundLocation - _myTransform->getPosition()).magnitude();
	if ((soundLocation - _myTransform->getPosition()).magnitude() < _hearingDistance * intensity) {
		_soundTime = _soundTimeSearchTime;
		_soundLocation.set(soundLocation);
	}
}

void InvisibleEnemyAIComponent::setFindRadius(double radius)
{
	_radiusFindPlayer = std::min(_maxRadiusFindPlayer, std::max(_minRadiusFindPlayer, radius));
	_attackCooldownTime = _attackCooldown;
}

void InvisibleEnemyAIComponent::justLostSight()
{
	_justLostSightTime = _lostSightSearchTime;
	_lastKnownPosition = _transformPlayer->getPosition();
}

void InvisibleEnemyAIComponent::createFSM()
{
	_ai = new FSM(this);

	FindState* find = createState<FindState>("findState"); 
	find->setFindRadius(&_radiusFindPlayer);
	find->setJustLostTime(&_justLostSightTime);

	GoTowardsPlayerState* towardsPlayer = createState<GoTowardsPlayerState>("towardsPlayer");

	AttackPlayerState* attackPlayer = createState<AttackPlayerState>("attackPlayer");
	attackPlayer->setHealthComp(_playerHealth);
	attackPlayer->setAudioSource(_audioSource);
	attackPlayer->setAttackCoolDown(_attackCooldown);
	attackPlayer->setAttackCoolDownTime(&_attackCooldownTime);
	attackPlayer->setRange(_attackRange);

	TowardsSoundState* towardsSound = createState<TowardsSoundState>("towardsSound");
	towardsSound->setSoundPos(&_soundLocation);

	LostSightTransition* lostSightTransition = createTransition<LostSightTransition>();
	lostSightTransition->setSightingDistance(&_sightingDistance);
	lostSightTransition->setPlayerVisibilityComp(_playerVisibility);

	GainSightTransition* gainSightTransition = createTransition<GainSightTransition>();
	gainSightTransition->setSightingDistance(&_sightingDistance);
	gainSightTransition->setPlayerVisibilityComp(_playerVisibility);

	InRangeTransition* inRangeTransition = createTransition<InRangeTransition>();
	inRangeTransition->setRange(_attackRange);

	LoudSoundTransition* loudSoundTransition = createTransition<LoudSoundTransition>();
	loudSoundTransition->setSoundTime(&_soundTime);

	NoSoundTransition* noSoundTransition = createTransition<NoSoundTransition>();
	noSoundTransition->setSoundTime(&_soundTime);

	//From find goes to the player or a loud sound
	_ai->add(find, gainSightTransition, towardsPlayer);
	_ai->add(find, loudSoundTransition, towardsSound);

	//If I'm going towards the player, if i lose sight I go to find, if I'm in range I attack
	_ai->add(towardsPlayer, lostSightTransition, find);
	_ai->add(towardsPlayer, inRangeTransition, attackPlayer);

	//If I'm going towards a sound, if there is nothing there I go to find, if I find the player i go towards him
	_ai->add(towardsSound, noSoundTransition, find);
	_ai->add(towardsSound, gainSightTransition, towardsPlayer);

	//If I lose sight of the player, I try to find him
	_ai->add(attackPlayer, lostSightTransition, find);

	_ai->setInitialState(find);
}

template<typename T>
T* InvisibleEnemyAIComponent::createState(const char* name)
{
	T* state = new T();
	state->name = name;
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
	}

	double distance = (comp->getMyTransform()->getPosition() - _targetPos).magnitude();

	//If I arrived to destination, I change it
	if (distance < 1) {
		Vector3 dirVector = Vector3(-1.0 + 2.0 * ((float)rand()) / RAND_MAX, comp->getMyTransform()->getPosition().getY(), -1.0 + 2.0 * ((float)rand()) / RAND_MAX).normalize();
		_targetPos = comp->getPlayerTransform()->getPosition() + (dirVector * *_radiusFromPlayer);
	}
	comp->moveTowardsPos(_targetPos);
}


void InvisibleEnemyAIComponent::GoTowardsPlayerState::execute(Component* component)
{
	CAST_COMPONENT;

	//Move towards player at normal speed
	comp->moveTowardsPos(comp->getPlayerTransform()->getPosition());
}


void InvisibleEnemyAIComponent::AttackPlayerState::execute(Component* component)
{
	CAST_COMPONENT;

	const Vector3& playerPos = comp->getPlayerTransform()->getPosition();
	const Vector3& myPos = comp->getMyTransform()->getPosition();

	//If I'm still in range & cd is gone
	if ((playerPos - myPos).magnitude() < _attackRange && *_attackCooldownTime < 0.0f) {
		*_attackCooldownTime = _attackCooldown;
		_playerHealth->loseHPs();
		_audioSource->playAudio(1);
	}

	//Move towards player while slowed
	comp->moveTowardsPos(playerPos);
}


void InvisibleEnemyAIComponent::TowardsSoundState::execute(Component* component)
{
	CAST_COMPONENT;

	comp->moveTowardsPos(*_soundPos);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------
//-------------  TRANSITIONS     TRANSITIONS    TRANSITIONS    TRANSITIONS    TRANSITIONS    TRANSITIONS    TRANSITIONS    TRANSITIONS  -------------
//---------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------

bool InvisibleEnemyAIComponent::LostSightTransition::evaluate(Component* component)
{
	CAST_COMPONENT;

	//If player is not visible, i just lost sight on him but i look close to where he was
	if (!_playerVis->getVisible()){ 
		comp->setFindRadius(0.0); 
		return true;
	}

	const Vector3& playerPos = comp->getPlayerTransform()->getPosition();
	const Vector3& myPos = comp->getMyTransform()->getPosition();

	//If ray doesnt hit anything static, that means we have direct sight towards the player
	RayCast::RayCastHit ray = RayCast(myPos, playerPos, RayCast::Type::Static).getRayCastInformation();
	if (ray.hit || (playerPos - myPos).magnitude() > *_sightingDistance) {
		comp->justLostSight();
		comp->slowAfterHit(false);
		return true;
	}

	return false;
}

bool InvisibleEnemyAIComponent::GainSightTransition::evaluate(Component* component)
{
	CAST_COMPONENT;

	//If player is not visible, i cant gain sight on him
	if (!_playerVis->getVisible())
		return false;
	
	const Vector3& playerPos = comp->getPlayerTransform()->getPosition();
	const Vector3& myPos = comp->getMyTransform()->getPosition();

	if ((playerPos - myPos).magnitude() > * _sightingDistance)
		return false;

	//If ray doesnt hit anything static, that means we have direct sight towards the player
	RayCast::RayCastHit ray = RayCast(myPos, playerPos, RayCast::Type::Static).getRayCastInformation();
	if (!ray.hit) {
		comp->setFindRadius(0.0);
		return true;
	}

	return false;
}

bool InvisibleEnemyAIComponent::LoudSoundTransition::evaluate(Component* component)
{
	return *_soundTime > 0;
}

bool InvisibleEnemyAIComponent::NoSoundTransition::evaluate(Component* component)
{
	return *_soundTime <= 0;
}

bool InvisibleEnemyAIComponent::InRangeTransition::evaluate(Component* component)
{
	CAST_COMPONENT;

	const Vector3& playerPos = comp->getPlayerTransform()->getPosition();
	const Vector3& myPos = comp->getMyTransform()->getPosition();

	//If I'm in range, i slow down
	if ((playerPos - myPos).magnitude() < _attackRange) {
		comp->slowAfterHit(true);
		return true;
	}
	return false;
}
