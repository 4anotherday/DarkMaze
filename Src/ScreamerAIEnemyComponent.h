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

	//TBD: Given by lua or gameobject itself?
	double _rangeToAttack;
private:
	AudioSourceComponent* _audioSource;
	Transform* _tranformPlayer;
	Transform* _transformEnemy;
	RigidBodyComponent* _rigidBodyEnemy;

	bool _startToMove;
	bool _startScream;
};

#endif // !SCREAMERAIMENEMYCOMPONENT_H