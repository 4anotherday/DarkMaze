#pragma once

#ifndef KEYCOMPONENT_H
#define KEYCOMPONENT_H

#include "InteractiveObjectComponent.h"

class GameObject;
class PlayerInteractiveComponent;
class PlayerKeysComponent;
class AudioSourceComponent;

class KeyComponent : public InteractiveObjectComponent
{
public:

	KeyComponent();
	~KeyComponent();

	/// <summary>
	/// Initializes the component, called once at the start of the execution
	/// </summary>
	virtual void start() override;

	/// <summary>
	/// Make the action when player interacts with the object
	/// </summary>
	virtual void interact() override;

	void onTrigger(GameObject* other) override;

private:

	PlayerInteractiveComponent* _plInteractive;
	PlayerKeysComponent* _playerKeys;
	AudioSourceComponent* _audio;
};

#endif // !KEYCOMPONENT_H