#include "UserComponentsIDs.h"
#include "KeyComponent.h"
#include "PlayerInteractiveComponent.h"
#include "PlayerKeysComponent.h"
#include "AudioSourceComponent.h"
#include "Engine.h"
#include "GameObject.h"

ADD_COMPONENT(KeyComponent)

KeyComponent::KeyComponent() : InteractiveObjectComponent(UserComponentId::KeyComponent), _plInteractive(nullptr), _playerKeys(nullptr)
{
}

KeyComponent::~KeyComponent()
{
}

void KeyComponent::start()
{
	_plInteractive = static_cast<PlayerInteractiveComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::PlayerInteractiveComponent));
	_playerKeys = static_cast<PlayerKeysComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::PlayerKeysComponent));
	_audio = static_cast<AudioSourceComponent*>(_gameObject->getComponent(ComponentId::AudioSource));
}

void KeyComponent::interact()
{
	if (_playerKeys != nullptr)
	{
		_playerKeys->addKey();
		if (_plInteractive != nullptr)
		{
			//I set the interactiveObject to nullptr, because I want to destoy it
			_plInteractive->setObject(nullptr);
			_audio->playAudio(0);
			Engine::getInstance()->remGameObjectString(_gameObject->getName());
		}
	}
}

void KeyComponent::onTrigger(GameObject* other)
{
	if (other->getName() == "Player") {
		interact();
	}
}
