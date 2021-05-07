#include "DeactivatableObjectComponent.h"

DeactivatableObjectComponent::DeactivatableObjectComponent(UserComponentId::UserComponentId id) :Component(id), _active(true)
{
}

void DeactivatableObjectComponent::setActive(bool active)
{
	_active = active;
	if (_active)
		onEnable();
	else 
		onDisable();
}
