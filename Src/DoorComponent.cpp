#include "UserComponentsIDs.h"
#include "DoorComponent.h"
#include "PlayerInteractiveComponent.h"
#include "PlayerKeysComponent.h"
#include "Engine.h"
#include "GameObject.h"

ADD_COMPONENT(DoorComponent)

DoorComponent::DoorComponent() : InteractiveObjectComponent(UserComponentId::DoorComponent),_plInteractive(nullptr)
{
}

DoorComponent::~DoorComponent()
{
}

void DoorComponent::start()
{
	_plInteractive = static_cast<PlayerInteractiveComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::PlayerInteractiveComponent));
	_playerKeys = static_cast<PlayerKeysComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::PlayerKeysComponent));
}

void DoorComponent::interact()
{
	if (_playerKeys != nullptr)
	{
		if (_playerKeys->getKeys() > 0)
		{
			_playerKeys->spendKey();
			
			if (_plInteractive != nullptr) 
			{
				//I set the interactiveObject to nullptr, because I want to destoy it 
				_plInteractive->setObject(nullptr);
				Engine::getInstance()->remGameObjectString(_gameObject->getName());
			}
		}		
	}
}



