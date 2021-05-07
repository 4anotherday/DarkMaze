#pragma once
#ifndef TRAPCOMPONENT_H
#define TRAPCOMPONENT_H
#include "DeactivatableObjectComponent.h"
class TrapComponent :
	public DeactivatableObjectComponent
{

public:
	TrapComponent();

	/// <summary>
	/// kills the player if the trap is active
	/// </summary>
	/// <param name="other">the collision gameObject</param>
	virtual void onCollision(GameObject* other)override;
};
#endif // !TRAPCOMPONENT_H

