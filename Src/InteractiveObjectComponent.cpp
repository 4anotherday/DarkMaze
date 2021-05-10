#include "InteractiveObjectComponent.h"
#include "UserComponentsIDs.h"
#include "PlayerInteractiveComponent.h"
#include "GameObject.h"

//ADD_COMPONENT(InteractiveObjectComponent)

InteractiveObjectComponent::InteractiveObjectComponent(unsigned int id) : Component(id),_distance(30.0f)
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

void InteractiveObjectComponent::interact()
{
}
