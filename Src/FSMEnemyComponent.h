#pragma once

#ifndef FSMENEMYCOMPONENT_H
#define FSMENEMYCOMPONENT_H

#include "Component.h"

class Transform;
class AudioSourceComponent;

class FSMEnemyComponent : public Component
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	FSMEnemyComponent();
	/// <summary>
	/// Destructor of the class
	/// </summary>
	~FSMEnemyComponent();

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
	virtual void startState();
	/// <summary>
	/// State that enemy realize when player is near.
	/// Do not override this method.
	/// </summary>
	virtual void actionState();

	double _distanceAction;
private:
	AudioSourceComponent* _audioSource;
	Transform* _trPlayer;
	Transform* _trEnemy;

	bool _action;
};

#endif // !FSMENEMYCOMPONENT_H