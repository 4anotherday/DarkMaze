#include "UserComponentsIDs.h"
#include "FirstAidKitComponent.h"
#include "HealthComponent.h"
#include "PlayerInteractiveComponent.h"
#include "Engine.h"
#include "GameObject.h"

ADD_COMPONENT(FirstAidKitComponent)

FirstAidKitComponent::FirstAidKitComponent() : InteractiveObjectComponent(UserComponentId::FirstAidKitComponent),_healthAmount(1),_health(nullptr),_plInteractive(nullptr)
{
}

FirstAidKitComponent::~FirstAidKitComponent()
{
}

void FirstAidKitComponent::start()
{
	_health = static_cast<HealthComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::HealthComponent));
	_plInteractive = static_cast<PlayerInteractiveComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::PlayerInteractiveComponent));
}

void FirstAidKitComponent::interact()
{
	if (_health != nullptr)
	{
		_health->addHPs(_healthAmount);
		//I set the interactiveObject to nullptr, because I want to destoy it 
		_plInteractive->setObject(nullptr);
		Engine::getInstance()->remGameObjectString(_gameObject->getName());
	}
}



