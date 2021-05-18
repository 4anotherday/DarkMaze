#include "UserComponentsIDs.h"
#include "FirstAidKitComponent.h"
#include "HealthComponent.h"
#include "PlayerInteractiveComponent.h"
#include "AudioSourceComponent.h"
#include "Engine.h"
#include "GameObject.h"
#include "includeLUA.h"

ADD_COMPONENT(FirstAidKitComponent)

FirstAidKitComponent::FirstAidKitComponent() : InteractiveObjectComponent(UserComponentId::FirstAidKitComponent), _healthAmount(1), _health(nullptr), _plInteractive(nullptr)
{
}

FirstAidKitComponent::~FirstAidKitComponent()
{
}

void FirstAidKitComponent::awake(luabridge::LuaRef& data)
{
	if (LUAFIELDEXIST(HealthAmount))
	{
		_healthAmount = GETLUAFIELD(HealthAmount, unsigned int);
	}
}

void FirstAidKitComponent::start()
{
	_health = static_cast<HealthComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::HealthComponent));
	_plInteractive = static_cast<PlayerInteractiveComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::PlayerInteractiveComponent));
	_audio = static_cast<AudioSourceComponent*>(_gameObject->getComponent(ComponentId::AudioSource));
}

void FirstAidKitComponent::interact()
{
	if (_health != nullptr)
	{
		_health->addHPs(_healthAmount);

		if (_plInteractive != nullptr)
		{
			//I set the interactiveObject to nullptr, because I want to destoy it
			_plInteractive->setObject(nullptr);
			Engine::getInstance()->remGameObjectString(_gameObject->getName());
			_audio->playAudio(0);
		}
	}
}