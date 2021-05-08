#include "ScreamerAIEnemyComponent.h"
#include "UserComponentsIDs.h"
#include "Transform.h"
#include "AudioSourceComponent.h"
#include "GameObject.h"
#include "Engine.h"
#include "RigidBodyComponent.h"
#include "EngineTime.h"
#include "ParticleSystemComponent.h"
#include "includeLUA.h"
#include "InvisibleEnemyAIComponent.h"
#include "RayCast.h"

ADD_COMPONENT(ScreamerAIEnemyComponent)

ScreamerAIEnemyComponent::ScreamerAIEnemyComponent() : Component(UserComponentId::ScreamerAIEnemyComponent), _detectionRange(), _invisibleEnemy(nullptr),
 _tranformPlayer(nullptr), _initialTransformEnemy(), _transformEnemy(nullptr), _readyToMove(false), _audioSource(nullptr), _rigidBodyEnemy(nullptr),
_particleSystem(nullptr), _dead(false), _elapsedFollowTime(0.0f), _elapsedDyingTime(0.0f), _lastPlayerPos(), _moving(false), _idleSoundOn(false), _screamingSoundOn(false),

//some random values
_followTime(3.0f), _moveSpeed(5.0f), _shoutIntensityIdle(0.1f), _shoutIntensityAttack(1.0f), _dyingTime (2.0f)
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
	_initialTransformEnemy = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform))->getPosition();
	_transformEnemy = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_audioSource = static_cast<AudioSourceComponent*>(_gameObject->getComponent(ComponentId::AudioSource));
	_particleSystem = GETCOMPONENT(ParticleSystemComponent, ComponentId::ParticleSystem);

	_invisibleEnemy = static_cast<InvisibleEnemyAIComponent*>(Engine::getInstance()->findGameObject("InvisibleEnemy")->
		getComponent(UserComponentId::InvisibleEnemyAIComponent));
}

void ScreamerAIEnemyComponent::update()
{
	const Vector3& currentPlayerPos = _tranformPlayer->getPosition();
	const Vector3& currentEnemyPos  = _transformEnemy->getPosition();

	double distance = (currentPlayerPos - currentEnemyPos).magnitude();
	//std::cout << distance << std::endl;
	if (!_screamingSoundOn) {
		if (distance <= _detectionRange) {
			_readyToMove = true;
			//std::cout << "inside detection range" << std::endl;
		}
		else if (!_dead) {
			//_invisibleEnemy->sound(currentPlayerPos, _shoutIntensityIdle);
			//std::cout << "outside detection range" << std::endl;
			idlestate();
		}

		//if moving but the player manages to get out of the distance range
		if (distance > _detectionRange && _readyToMove && !_dead) {
			std::cout << "player moved outside the detection range" << std::endl;
			_readyToMove = false;
			_moving = false;
			_elapsedFollowTime = 0;
		}
	}
	if (_readyToMove) {
		//If ray doesnt hit anything static, that means we have direct sight towards the player
		RayCast::RayCastHit ray = RayCast(currentEnemyPos, currentPlayerPos, RayCast::Type::Static).getRayCastInformation();
		if (!ray.hit)
		{
			//std::cout << "player transform found & changed" << std::endl;
			_lastPlayerPos = currentPlayerPos;
			_moving = true;
		}
		movingState();
		_elapsedFollowTime += EngineTime::getInstance()->deltaTime();

		if ((distance <= _detectionRange / 2) ||
			_elapsedFollowTime >= _followTime) {
			//std::cout << "screaming state" << std::endl;
			_invisibleEnemy->sound(currentPlayerPos, _shoutIntensityAttack);
			screamingState();
		}
	}

	if (_dead) {
		_elapsedDyingTime += EngineTime::getInstance()->deltaTime();
		if (_elapsedDyingTime >= _dyingTime) {
			_audioSource->stopChannel(1);
			Engine::getInstance()->remGameObject(_gameObject);
		}
	}
}


void ScreamerAIEnemyComponent::idlestate()
{
	//0 is the audio corresponding to idle
	if (!_idleSoundOn) {
		_audioSource->setAudioLoop(0, -1);
		_audioSource->playAudio(0);
		_idleSoundOn = true;
	}
	Vector3 trEnem = _transformEnemy->getPosition();
	if (_initialTransformEnemy != _transformEnemy->getPosition()) {
		_transformEnemy->setPosition(_initialTransformEnemy);

		/*Vector3 dir =  (_initialTransformEnemy).normalize() - _transformEnemy->getPosition();
		dir = dir * _moveSpeed;
		std::cout << dir.getX() << " " << dir.getY() << " " << dir.getZ() << " " << std::endl;
		_rigidBodyEnemy->addForce(dir);*/
		//TODO: particle effect back to its transform, MAYBE
		//_particleSystem->setEnabled(true);
		/*Vector3 dir = _initialTransformEnemy->getPosition();
		_rigidBodyEnemy->moveTo(dir);*/
	}

}

void ScreamerAIEnemyComponent::movingState()
{
	if (!_moving) return;

	_audioSource->stopChannel(0);

	//Vector3 dir = (_tranformPlayer->getPosition()).normalize() - _transformEnemy->getPosition();
	Vector3 dir = (_lastPlayerPos) - _transformEnemy->getPosition();
	dir.normalize();
	dir = dir * _moveSpeed;
	dir.setY(0.0);

	std::cout << dir.getX() << " " << dir.getY() << " " << dir.getZ() << " " << std::endl;
	_rigidBodyEnemy->setLinearVelocity(dir);

	/*Vector3 dir = _tranformPlayer->getPosition();
	_rigidBodyEnemy->moveTo(dir);*/
}

void ScreamerAIEnemyComponent::screamingState()
{
	_idleSoundOn = false;
	//1 corresponds with AttackAudio
	if (!_screamingSoundOn) {
		_audioSource->playAudio(1);
		int a = _audioSource->getVolumeChannel(0); // esto es 0??
		_audioSource->setVolumeChannel(4, 1);
		_screamingSoundOn = true;
	}
	//_particleSystem->setEnabled(true);
	_dead = true;
	// WARN THE INVISIBLE ENEMY 
}
