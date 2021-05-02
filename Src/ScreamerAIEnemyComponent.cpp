#include "ScreamerAIEnemyComponent.h"
#include "UserComponentsIDs.h"
#include "Transform.h"
#include "AudioSourceComponent.h"
#include "GameObject.h"
#include "Engine.h"
#include "RigidBodyComponent.h"
#include "EngineTime.h"
#include "ParticleSystemComponent.h"
#include "Vector3.h"
#include "includeLUA.h"

ADD_COMPONENT(ScreamerAIEnemyComponent)

ScreamerAIEnemyComponent::ScreamerAIEnemyComponent() : Component(UserComponentId::ScreamerAIEnemyComponent), _detectionRange(),
 _tranformPlayer(nullptr), _transformEnemy(nullptr), _startToMove(false), _audioSource(nullptr), _rigidBodyEnemy(nullptr),
_particleSystem(nullptr), _dead(false), _elapsedFollowTime(0.0f), _elapsedDyingTime(0.0f),

//some random values
_followTime(3.0f), _moveSpeed(5.0f), _shoutIntensityIdle(0.5f), _shoutIntensityAttack(2.0f), _dyingTime (1.0f)
{
}

ScreamerAIEnemyComponent::~ScreamerAIEnemyComponent()
{
}

void ScreamerAIEnemyComponent::awake(luabridge::LuaRef& data)
{
	if (LUAFIELDEXIST(ShoutIntensityAttack))	_shoutIntensityAttack = GETLUAFIELD(ShoutIntensityAttack, float);
	if (LUAFIELDEXIST(ShoutIntensityIdle))		_shoutIntensityIdle = GETLUAFIELD(ShoutIntensityIdle, float);
	if (LUAFIELDEXIST(DetectionRange))			_detectionRange = GETLUAFIELD(DetectionRange, float);
	if (LUAFIELDEXIST(FollowTime))				_followTime = GETLUAFIELD(FollowTime, float);
	if (LUAFIELDEXIST(DyingTime))				_dyingTime = GETLUAFIELD(DyingTime, float);
	if (LUAFIELDEXIST(MoveSpeed))				_moveSpeed = GETLUAFIELD(MoveSpeed, float);
}

void ScreamerAIEnemyComponent::start()
{
	_rigidBodyEnemy = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
	_tranformPlayer = static_cast<Transform*>(Engine::getInstance()->findGameObject("Player")->getComponent(ComponentId::Transform));
	_transformEnemy = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_audioSource = static_cast<AudioSourceComponent*>(_gameObject->getComponent(ComponentId::AudioSource));

	_particleSystem = GETCOMPONENT(ParticleSystemComponent, ComponentId::ParticleSystem);
}

void ScreamerAIEnemyComponent::update()
{
	const Vector3& currentPlayerPos = _tranformPlayer->getPosition();
	const Vector3& currentEnemyPos  = _transformEnemy->getPosition();

	double distance = (currentPlayerPos - currentEnemyPos).magnitude();
	if (distance <= _detectionRange) {
		_startToMove = true;	
		_elapsedFollowTime = 0;
	}
	else idlestate();

	if (_startToMove) {
		movingState();
		_elapsedFollowTime += EngineTime::getInstance()->deltaTime();

		if ((distance <= _detectionRange / 3) ||
			_elapsedFollowTime >= _followTime) {
			screamingState();
		}
	}

	if (_dead) {
		_elapsedDyingTime += EngineTime::getInstance()->deltaTime();
		if (_elapsedDyingTime >= _dyingTime) {
			_audioSource->stopChannel();
			Engine::getInstance()->remGameObject(_gameObject);
		}
	}
}


void ScreamerAIEnemyComponent::idlestate()
{
	//0 is the audio corresponding to idle
	_audioSource->playAudio(0);
}

void ScreamerAIEnemyComponent::movingState()
{
	//TODO: Parar audio idle	
	_audioSource->stopChannel();

	//TODO: Raycast o pathfinding para encontrar el camino al jugador
	Vector3 dir = _tranformPlayer->getPosition();
	_rigidBodyEnemy->moveTo(dir);
}

void ScreamerAIEnemyComponent::screamingState()
{
	//1 corresponds with attackAudio
	_audioSource->playAudio(1);
	_particleSystem->setEnabled(true);
	_dead = true;
	// WARN THE INVISIBLE ENEMY 
}
