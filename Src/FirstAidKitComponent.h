#pragma once

#ifndef FIRSTAIDKITCOMPONENT_H
#define FIRSTAIDKITCOMPONENT_H

#include "InteractiveObjectComponent.h"

class GameObject;
class HealthComponent;
class PlayerInteractiveComponent;
class AudioSourceComponent;

class FirstAidKitComponent : public InteractiveObjectComponent
{
public:

	FirstAidKitComponent();
	~FirstAidKitComponent();

	virtual void awake(luabridge::LuaRef& data) override;

	/// <summary>
	/// Initializes the component, called once at the start of the execution
	/// </summary>
	virtual void start() override;

	/// <summary>
	/// Make the action when player interacts with the object
	/// </summary>
	virtual void interact() override;

private:

	HealthComponent* _health;
	PlayerInteractiveComponent* _plInteractive;
	AudioSourceComponent* _audio;
	unsigned int _healthAmount;
};

#endif // !FIRSTAIDKITCOMPONENT_H