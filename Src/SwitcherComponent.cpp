#include "includeLUA.h"
#include "Engine.h"
#include "LightComponent.h"
#include "GameObject.h"
#include "Exceptions.h"
#include "SwitcherComponent.h"
#include "AudioSourceComponent.h"

ADD_COMPONENT(SwitcherComponent)

SwitcherComponent::SwitcherComponent() : InteractiveObjectComponent(UserComponentId::SwitcherComponent), _light(nullptr)
{
}

void SwitcherComponent::awake(luabridge::LuaRef& data)
{
	if (LUAFIELDEXIST(ObjName))
		_deactivatableName = GETLUASTRINGFIELD(ObjName);
	else throw ComponentException("trap name not found");
}

void SwitcherComponent::start()
{
	InteractiveObjectComponent::start();
	GameObject* go = Engine::getInstance()->findGameObject(_deactivatableName);
	_audio = static_cast<AudioSourceComponent*>(_gameObject->getComponent(ComponentId::AudioSource));
	if (go == nullptr)
		throw NullptrObjectException("trap not found");

	_light = static_cast<LightComponent*>(go->getComponent(ComponentId::LightComponent));
	if (_light == nullptr)
		throw ComponentException("TrapComponent not found in an object");
}

void SwitcherComponent::interact()
{
	_light->setEnabled(!_light->getEnabled());
	_audio->playAudio(0);
}