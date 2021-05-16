#pragma once
#ifndef _KAMIKAZE_ENEMY_COMPONENT_
#define _KAMIKAZE_ENEMY_COMPONENT_

#include "Component.h"
#include "Vector3.h"

class Transform;
class RigidBodyComponent;
class ColliderComponent;
class InvisibleEnemyAIComponent;
class HealthComponent;
class ParticleSystemComponent;
class AudioSourceComponent;
class RenderObjectComponent;
class PlayerVisibilityComponent;

class KamikazeEnemyComponent : public Component {
public:
	KamikazeEnemyComponent();

	~KamikazeEnemyComponent();

	void awake(luabridge::LuaRef& data) override;

	void start() override;

	void update() override;

private:

	/// <summary>
	/// The enemy keeps moving towards given position until it's reached
	/// </summary>
	/// <param name="pos">Target position</param>
	void moveTowardsPos(const Vector3& pos);
	
	/// <summary>
	/// Called when following timer expires
	/// </summary>
	void explode();

	RigidBodyComponent* _rb;
	Transform* _tr;
	Transform* _playerTr;
	InvisibleEnemyAIComponent* _invisibleEnemy;
	HealthComponent* _playerHealth;
	ParticleSystemComponent* _particleSystem;
	AudioSourceComponent* _audioSource;
	RenderObjectComponent* _renderObject;
	PlayerVisibilityComponent* _playerVisibility;

	//Position where player was last seen
	Vector3 _lastPlayerPos;
	//True when enemy is following player
	bool _active;
	//True if enemy has already exploded
	bool _dead;
	//Time elapsed since enemy started following player
	float _elapsedFollowTime;
	//Time elapsed since particles started appearing
	float _elapsedParticlesTime;

	//Range of one-shot explosion
	float _nearExplosionRange;
	//Range of soft explosion
	float _farExplosionRange;
	//Enemy's lifetime since it started following player 
	float _followTime;
	//Enemy's vision range
	float _visionRange;
	//Enemy's shouting intensity to be heared by invisible enmey
	float _shoutingIntensity;
	//Enemy's movement speed
	float _speed;
	//Duration in seconds of explosion particles
	float _particlesDuration;
};

#endif // !_KAMIKAZE_ENEMY_COMPONENT_
