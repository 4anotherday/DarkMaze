#pragma once

#ifndef SCREAMERAIMENEMYCOMPONENT_H
#define SCREAMERAIMENEMYCOMPONENT_H

#include "Component.h"

class Transform;
class RigidBodyComponent;
class AudioSourceComponent;
class ParticleSystemComponent;

class ScreamerAIEnemyComponent : public Component
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	ScreamerAIEnemyComponent();
	/// <summary>
	/// Destructor of the class
	/// </summary>
	~ScreamerAIEnemyComponent();

	/// <summary>
	/// Initializes the variables the component needs from lua
	/// </summary>
	/// <param name="data"></param>
	void awake(luabridge::LuaRef& data) override;

	/// <summary>
	/// Initializes the component, called once at the start of the execution
	/// </summary>
	void start() override;

	/// <summary>
	/// Checks the distance between 
	/// </summary>
	void update() override;

protected:
	/// <summary>
	/// State where the screamer stays in its place and makes noises to attract the player
	/// </summary>
	virtual void idlestate();

	/// <summary>
	/// State where the screamer detects the player and moves towards the player. It is done with raycast
	/// Do not override this method.
	/// </summary>
	virtual void movingState();

	/// <summary>
	/// State where the screamer get close enough to the player and starts screaming heavily, noticing the invisible enemy and scaring the player
	/// Close is considered its detect range/3
	/// Do not override this method.
	/// </summary>
	virtual void screamingState();

private:
	ParticleSystemComponent* _particleSystem;
	RigidBodyComponent* _rigidBodyEnemy;
	AudioSourceComponent* _audioSource;
	Transform* _tranformPlayer;
	Transform* _transformEnemy;

	//TODO:Meter InvisibleAIcomponent y avisarle

	//Enemy's timer to chase the player	 
	float _elapsedFollowTime;
	float _followTime;
	//Enemy's timer to die when it finds the player or when the follow time expires
	float _elapsedDyingTime;
	float _dyingTime;
	
	//Enemy's shouting intensity when it is in idle state
	float _shoutIntensityIdle;
	//Enemy's shouting intensity when it finds the player and screams
	float _shoutIntensityAttack;
	//Enemy's detection range to detect the player, if detected, it procceeds to move towards the player
	float _detectionRange;

	float _moveSpeed;

	//Starts moving if the player entered within its detection range
	bool _startToMove;
	//If dead, performs the scream and the particle's effect
	bool _dead;
};

#endif // !SCREAMERAIMENEMYCOMPONENT_H