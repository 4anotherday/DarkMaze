#pragma once

#ifndef PLAYERINTERACTIVECOMPONENT_H
#define PLAYERINTERACTIVECOMPONENT_H

#include "Component.h"
#include "KeyCodes.h"

class InteractiveObjectComponent;
class KeyBoardInput;
class Transform;

class PlayerInteractiveComponent : public Component
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	PlayerInteractiveComponent();
	/// <summary>
	/// Destructor of the class
	/// </summary>
	~PlayerInteractiveComponent();

	/// <summary>
	/// Initializes the component, called once at the start of the execution
	/// </summary>
	void start() override;

	/// <summary>
	/// Checks if the player has pressed the key to interact
	/// </summary>
	void update() override;

	/// <summary>
	/// Sets the object to interact
	/// </summary>
	void setObject(InteractiveObjectComponent* ob);

private:
	/// <summary>
	/// Checks it the interactive object is still in range
	/// </summary>
	bool _isStillTrigger();

	InteractiveObjectComponent* _objectToInteract;
	KeyBoardInput* _keyboard;
	Transform* _transform;

	KeyCode _key;

};

#endif // !PLAYERINTERACTIVECOMPONENT_H