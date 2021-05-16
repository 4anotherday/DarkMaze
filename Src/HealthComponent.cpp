#include "HealthComponent.h"
#include "UserComponentsIDs.h"
#include "includeLUA.h"
#include "GameManagerComponent.h"
#include "Engine.h"
#include "GameObject.h"

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
	_healthPoints += n;
	if(_healthPoints>=_maxHealthPoints) _healthPoints = _maxHealthPoints;
}

void HealthComponent::loseHPs()
{
	_healthPoints -= 1;
	if (_healthPoints <= 0) {
		_healthPoints = 0;
		onDead();
	}
}

void HealthComponent::loseHPs(unsigned int n)
{
	_healthPoints -= n;
	if (_healthPoints <= 0) {
		_healthPoints = 0;
		onDead();
	}
}

void HealthComponent::reset()
{
	_healthPoints = _maxHealthPoints;
}

void HealthComponent::onDead()
{	
	GameObject * go = Engine::getInstance()->findGameObject("GameManager");
	GameManagerComponent* gm = GETCOMPONENT(GameManagerComponent, UserComponentId::GameManagerComponent);
	gm->toMenu();
}
