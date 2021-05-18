#include "UserComponentsIDs.h"
#include "DoorComponent.h"
#include "PlayerInteractiveComponent.h"
#include "PlayerKeysComponent.h"
#include "Engine.h"
#include "GameObject.h"
#include "GameManagerComponent.h"
#include "AudioSourceComponent.h"

ADD_COMPONENT(DoorComponent)

DoorComponent::DoorComponent() : InteractiveObjectComponent(UserComponentId::DoorComponent), _plInteractive(nullptr),_playerKeys(nullptr)
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
				GameObject* go = Engine::getInstance()->findGameObject("GameManager");
				GameManagerComponent* gm = static_cast<GameManagerComponent*>(go->getComponent(UserComponentId::GameManagerComponent));
				gm->toMenu();
			}
		}
		else {
			GETCOMPONENT(AudioSourceComponent, ComponentId::AudioSource)->playAudio(0);
			GETCOMPONENT(AudioSourceComponent, ComponentId::AudioSource)->setVolumeChannel(0.1, 0);
		}
	}
}

void DoorComponent::onCollision(GameObject* other)
{
	if (other->getName() == "Player") {
		interact();
	}
}



