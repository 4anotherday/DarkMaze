#include "TrapComponent.h"
#include "UserComponentsIDs.h"
#include "Logger.h"
#include "HealthComponent.h"
#include "includeLUA.h"
#include "RenderObjectComponent.h"
#include "GameObject.h"
#include "AudioSourceComponent.h"

ADD_COMPONENT(TrapComponent)
TrapComponent::TrapComponent() :Component(UserComponentId::TrapComponent), _active(true), _renderObject(nullptr), _enabledMaterial("Practica1/Suelo"),
_disabledMaterial("Practica1/Suelo"), _log(nullptr)
{
}

TrapComponent::~TrapComponent()
{
}

void TrapComponent::start()
{
	_renderObject = GETCOMPONENT(RenderObjectComponent, ComponentId::RenderObject);
	_audio = GETCOMPONENT(AudioSourceComponent, ComponentId::AudioSource);
}

void TrapComponent::awake(luabridge::LuaRef& data)
{
	_log = Logger::getInstance();
	if (LUAFIELDEXIST(EnabledMaterial))
		_enabledMaterial = GETLUASTRINGFIELD(EnabledMaterial);
	else
		_log->log("EnabledMaterial not set", Logger::Level::WARN);

	if (LUAFIELDEXIST(DisabledMaterial))
		_disabledMaterial = GETLUASTRINGFIELD(DisabledMaterial);
	else
		_log->log("disabledMaterial not set", Logger::Level::WARN);
}

void TrapComponent::setActive(bool active)
{
	_active = active;
	if (_active)
		onEnable();
	else
		onDisable();
}

void TrapComponent::onEnable()
{
	_renderObject->setMaterial(_enabledMaterial);
}

void TrapComponent::onDisable()
{
	_renderObject->setMaterial(_disabledMaterial);
}

void TrapComponent::onTrigger(GameObject* other)
{
	HealthComponent* health = dynamic_cast<HealthComponent*>(other->getComponent(UserComponentId::HealthComponent));
	if (health != nullptr && _active) {
		health->loseHPs(health->getCurrentHP() / 2);
		_audio->playAudio(0);
		//_gameObject->setEnabled(false);
	}
}