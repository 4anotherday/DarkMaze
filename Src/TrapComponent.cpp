#include "TrapComponent.h"
#include "UserComponentsIDs.h"
#include "HealthComponent.h"
#include "GameObject.h"
ADD_COMPONENT(TrapComponent)
TrapComponent::TrapComponent() :DeactivatableObjectComponent(UserComponentId::TrapComponent)
{
}

void TrapComponent::onCollision(GameObject* other)
{
	HealthComponent* health = dynamic_cast<HealthComponent*>(other->getComponent(UserComponentId::HealthComponent));
	if (health != nullptr && _active) {
		health->loseHPs(health->getCurrentHP());


	}
}


