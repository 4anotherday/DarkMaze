#include "HealthComponent.h"
#include "UserComponentsIDs.h"

ADD_COMPONENT(HealthComponent)

HealthComponent::HealthComponent() : Component(UserComponentId::HealthComponent), _maxHealthPoints(), _healthPoints()
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
