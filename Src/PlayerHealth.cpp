#include "PlayerHealth.h"
#include "ComponentIDs.h"
#include "Component.h"

HealthComponent::HealthComponent(unsigned int healthPoints) :Component(ComponentId::HealthComponent), _maxHealthPoints(healthPoints), _healthPoints(healthPoints)
{}

HealthComponent::HealthComponent(unsigned int healthPoints, GameObject* go) : Component(ComponentId::HealthComponent, go), _maxHealthPoints(healthPoints), _healthPoints(healthPoints)
{}

void HealthComponent::addHPs(unsigned int n)
{
	_healthPoints += n;
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

}
