#include "InteractiveObjectComponent.h"
#include "PlayerInteractiveComponent.h"
#include "ColliderComponent.h"
#include "GameObject.h"
#include "Logger.h"
#include <iostream>

InteractiveObjectComponent::InteractiveObjectComponent(UserComponentId::UserComponentId id) : Component(id), _distance(30.0f), _log(nullptr)
{
}

InteractiveObjectComponent::~InteractiveObjectComponent()
{
}

void InteractiveObjectComponent::onTrigger(GameObject* other)
{
	PlayerInteractiveComponent* playerInt = static_cast<PlayerInteractiveComponent*>(other->getComponent(UserComponentId::PlayerInteractiveComponent));
	if (playerInt != nullptr) {
		playerInt->setObject(this);
	}
}

void InteractiveObjectComponent::start()
{
	_log = Logger::getInstance();
	SphereColliderComponent* col = GETCOMPONENT(SphereColliderComponent, ComponentId::SphereCollider);
	if (col != nullptr)
		_distance = col->getRadius() * .55;
	else {
		_distance = 1;
		_log->log("The trigger is not a sphere, using default distance", Logger::Level::WARN);
	}

}

void InteractiveObjectComponent::interact()
{
}
