#pragma once

#ifndef SCREAMERAIMENEMYCOMPONENT_H
#define SCREAMERAIMENEMYCOMPONENT_H

#include "Component.h"

class Transform;
class RigidBodyComponent;
class AudioSourceComponent;

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
	/// Initializes the component, called once at the start of the execution
	/// </summary>
	void start() override;

	/// <summary>
	/// Checks the distance between 
	/// </summary>
	void update() override;

protected:
	/// <summary>
	/// State that enemy realize when player is not near
	/// </summary>
	virtual void idlestate();

	/// <summary>
	/// State that enemy realize when player is near.
	/// Do not override this method.
	/// </summary>
	virtual void movingState();

	/// <summary>
	/// State that enemy realize when player is near.
	/// Do not override this method.
	/// </summary>
	virtual void screamingState();

	double _rangeToAttack;
private:
	AudioSourceComponent* _audioSource;
	Transform* _trPlayer;
	Transform* _trEnemy;
	RigidBodyComponent* _rigidBodyEnemy;

	bool _move;
};

#endif // !SCREAMERAIMENEMYCOMPONENT_H