#include "UserComponentsIDs.h"
#include "FirstAidKitComponent.h"
#include "HealthComponent.h"
#include "Engine.h"
#include "GameObject.h"

ADD_COMPONENT(FirstAidKitComponent)

FirstAidKitComponent::FirstAidKitComponent() : InteractiveObjectComponent(UserComponentId::FirstAidKitComponent),_healthAmount(1),_health(nullptr)
{
}

FirstAidKitComponent::~FirstAidKitComponent()
{
}

void FirstAidKitComponent::start()
{
	_health = static_cast<HealthComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::HealthComponent));
}

void FirstAidKitComponent::interact()
{
	if (_health != nullptr)
	{
		_health->addHPs(_healthAmount);
		//destroy firstaidkit
	}
}



