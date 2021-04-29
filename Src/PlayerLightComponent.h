#pragma once

#ifndef PLAYERLIGHTCOMPONENT_H
#define PLAYERLIGHTCOMPONENT_H

#include "Component.h"

class GameObject;
class LightComponent;
class Transform;

class PlayerLightComponent : public Component
{
public:
	/// <summary>
	/// Class constructor
	/// </summary>
	/// <param name="go"> Component game object</param>
	PlayerLightComponent();
	~PlayerLightComponent();

	void start() override;

	void update() override;
	
private:
	LightComponent* _playerLight;
	Transform* _transform;
};

#endif // !PLAYERLIGHTCOMPONENT_H