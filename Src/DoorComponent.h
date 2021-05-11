#pragma once

#ifndef DOORCOMPONENT_H
#define DOORCOMPONENT_H

#include "InteractiveObjectComponent.h"

class GameObject;
class PlayerInteractiveComponent;
class PlayerKeysComponent;

class DoorComponent : public InteractiveObjectComponent
{
public:

	DoorComponent();
	~DoorComponent();

	/// <summary>
	/// Initializes the component, called once at the start of the execution
	/// </summary>
	virtual void start() override;

	/// <summary>
	/// Make the action when player interacts with the object
	/// </summary>
	virtual void interact() override;

private:

	PlayerInteractiveComponent* _plInteractive;
	PlayerKeysComponent* _playerKeys;
};

#endif // !DOORCOMPONENT_H