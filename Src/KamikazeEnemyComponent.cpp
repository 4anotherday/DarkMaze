#include "KamikazeEnemyComponent.h"
#include "UserComponentsIDs.h"
#include "RigidBodyComponent.h"
#include "GameObject.h"
#include "RayCast.h"
#include "Transform.h"
#include "Engine.h"
#include "EngineTime.h"
#include "InvisibleEnemyAIComponent.h"
#include "HealthComponent.h"
#include "includeLUA.h"
#include "ParticleSystemComponent.h"
#include "AudioSourceComponent.h"
#include "RenderObjectComponent.h"
#include "PlayerVisibilityComponent.h"

ADD_COMPONENT(KamikazeEnemyComponent)

KamikazeEnemyComponent::KamikazeEnemyComponent() : Component(UserComponentId::KamikazeEnemyComponent),
	_rb(nullptr), _tr(nullptr), _playerTr(nullptr), _invisibleEnemy(nullptr), _playerHealth(nullptr),
	_audioSource(nullptr),_particleSystem(nullptr), _renderObject(nullptr),_playerVisibility(nullptr),
	_active(false), _dead(false), _lastPlayerPos(Vector3(0, 0, 0)),
	_elapsedFollowTime(0.0f), _elapsedParticlesTime(0.0f),

	//Default configuration values
	_nearExplosionRange(8.0f), _farExplosionRange(20.0f),
	_followTime(3.0f), _speed(40.0f), _visionRange(30.0f), _shoutingIntensity(0.6f),
	_particlesDuration(2.0f)
{}

KamikazeEnemyComponent::~KamikazeEnemyComponent()
{}

void KamikazeEnemyComponent::awake(luabridge::LuaRef& data)
{
	if (LUAFIELDEXIST(NearExplosionRange))	_nearExplosionRange = GETLUAFIELD(NearExplosionRange, float);
	if (LUAFIELDEXIST(FarExplosionRange))	_farExplosionRange = GETLUAFIELD(FarExplosionRange, float);
	if (LUAFIELDEXIST(FollowTime))			_followTime = GETLUAFIELD(FollowTime, float);
	if (LUAFIELDEXIST(VisionRange))			_visionRange = GETLUAFIELD(VisionRange, float);
	if (LUAFIELDEXIST(ShoutIntensity))		_shoutingIntensity = GETLUAFIELD(ShoutIntensity, float);
	if (LUAFIELDEXIST(Speed))				_speed = GETLUAFIELD(Speed, float);
	if (LUAFIELDEXIST(ParticlesDuration))	_particlesDuration = GETLUAFIELD(ParticlesDuration, float);
}

void KamikazeEnemyComponent::start()
{
	_rb = GETCOMPONENT(RigidBodyComponent, ComponentId::Rigidbody);

	_tr = GETCOMPONENT(Transform, ComponentId::Transform);

	//_particleSystem = GETCOMPONENT(ParticleSystemComponent, ComponentId::ParticleSystem);

	_audioSource = GETCOMPONENT(AudioSourceComponent, ComponentId::AudioSource);

	_renderObject= GETCOMPONENT(RenderObjectComponent, ComponentId::RenderObject);

	GameObject* player = Engine::getInstance()->findGameObject("Player");
	_playerTr = static_cast<Transform*>(player->getComponent(ComponentId::Transform));
	_playerVisibility = static_cast<PlayerVisibilityComponent*>(player->getComponent(UserComponentId::PlayerVisibilityComponent));
	_playerHealth = static_cast<HealthComponent*>(player->getComponent(UserComponentId::HealthComponent));

	_invisibleEnemy = static_cast<InvisibleEnemyAIComponent*>(Engine::getInstance()->findGameObject("InvisibleEnemy")->
		getComponent(UserComponentId::InvisibleEnemyAIComponent));
}

void KamikazeEnemyComponent::update()
{
	const Vector3& playerPos = _playerTr->getPosition();
	const Vector3& myPos = _tr->getPosition();

	//If ray doesnt hit anything static, that means we have direct sight towards the player
	RayCast::RayCastHit ray = RayCast(myPos, playerPos, RayCast::Type::Static).getRayCastInformation();
	if (!ray.hit && (playerPos - myPos).magnitude() < _visionRange && _playerVisibility->getVisible()) {
		_lastPlayerPos = playerPos;
		if (!_active) {
			_active = true;
			_audioSource->setAudioLoop(0, 0);
			_audioSource->playAudio(0);
			_elapsedFollowTime = 0;
		}
	}

	//When the enemy is following the player
	if (_active) {
		moveTowardsPos(_lastPlayerPos);
		_elapsedFollowTime += EngineTime::getInstance()->deltaTime();
		if (_elapsedFollowTime >= _followTime) {
			_invisibleEnemy->sound(_tr->getPosition(), _shoutingIntensity);
			explode();
		}
	}

	//When the enemy already exploded
	if (_dead) {
		_elapsedParticlesTime += EngineTime::getInstance()->deltaTime();
		if (_elapsedParticlesTime >= _particlesDuration) Engine::getInstance()->remGameObject(_gameObject);
	}
}

void KamikazeEnemyComponent::moveTowardsPos(const Vector3& pos)
{
	Vector3 dir =  pos - _tr->getPosition();
	dir.setY(0);
	if (dir.magnitude() < 0.2)
		return;
	dir = dir.normalize();
	dir = dir * _speed;
	_rb->addForce(dir);
}

void KamikazeEnemyComponent::explode()
{
	//_particleSystem->setEnabled(true);
	_active = false;
	_dead = true;

	_renderObject->setEnabled(false);
	_audioSource->stopChannel(0);
	_audioSource->setAudioLoop(1, 0);
	_audioSource->playAudio(1);

	//Damage player
	const Vector3& playerPos = _playerTr->getPosition();
	const Vector3& myPos = _tr->getPosition();
	float distance = (playerPos - myPos).magnitude();

	if (distance < _nearExplosionRange) {
		_playerHealth->loseHPs();
	}
	else if ( distance < _farExplosionRange) {
		_playerHealth->loseHPs(2);
	}
}
