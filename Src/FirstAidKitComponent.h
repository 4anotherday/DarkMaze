#pragma once

#ifndef FIRSTAIDKITCOMPONENT_H
#define FIRSTAIDKITCOMPONENT_H

#include "InteractiveObjectComponent.h"

class GameObject;
class HealthComponent;

class FirstAidKitComponent : public InteractiveObjectComponent
{
public:

	FirstAidKitComponent();
	~FirstAidKitComponent();

	virtual void start() override;

	virtual void interact() override;

private:

	HealthComponent* _health;

	unsigned int _healthAmount;
};

#endif // !FIRSTAIDKITCOMPONENT_H