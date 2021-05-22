#include "HealthComponent.h"
#include "UserComponentsIDs.h"
#include "includeLUA.h"
#include "GameManagerComponent.h"
#include "Engine.h"
#include "GameObject.h"
#include "CameraComponent.h"
#include "AudioSourceComponent.h"

ADD_COMPONENT(HealthComponent)

HealthComponent::HealthComponent() : Component(UserComponentId::HealthComponent), _maxHealthPoints(), _healthPoints()
{}

void HealthComponent::awake(luabridge::LuaRef& data)
{
	_maxHealthPoints = 100;
	if (LUAFIELDEXIST(HP))
		_maxHealthPoints = GETLUAFIELD(HP, int);
	_healthPoints = _maxHealthPoints;
}

void HealthComponent::addHPs(unsigned int n)
{
	GETCOMPONENT(CameraComponent, ComponentId::Camera)->setCompositor("JugadorVisionInjured", false);
	_healthPoints += n;
	if (_healthPoints >= _maxHealthPoints) _healthPoints = _maxHealthPoints;
}

void HealthComponent::loseHPs()
{
	loseHPs(1);
}

void HealthComponent::loseHPs(unsigned int n)
{
	_healthPoints -= n;
	if (_healthPoints <= 0) {
		GETCOMPONENT(CameraComponent, ComponentId::Camera)->setCompositor("JugadorVisionInjured", false);
		_healthPoints = 0;
		onDead();
	}
	else
		GETCOMPONENT(CameraComponent, ComponentId::Camera)->setCompositor("JugadorVisionInjured", true);
}

void HealthComponent::reset()
{
	_healthPoints = _maxHealthPoints;
}

void HealthComponent::onDead()
{
	GameObject* go = Engine::getInstance()->findGameObject("GameManager");
	GameManagerComponent* gm = static_cast<GameManagerComponent*>(go->getComponent(UserComponentId::GameManagerComponent));
	gm->toMenu(0);
}
