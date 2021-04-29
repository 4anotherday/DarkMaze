#include "FSMEnemyComponent.h"
#include "UserComponentsIDs.h"
#include "Transform.h"
#include "AudioSourceComponent.h"
#include "GameObject.h"
#include "Engine.h"

ADD_COMPONENT(FSMEnemyComponent)

FSMEnemyComponent::FSMEnemyComponent() : Component(UserComponentId::FSMEnemyComponent), _distanceAction(),
 _trPlayer(nullptr), _trEnemy(nullptr), _action(false)
{
}

FSMEnemyComponent::~FSMEnemyComponent()
{
}

void FSMEnemyComponent::start()
{
	_trPlayer = static_cast<Transform*>(Engine::getInstance()->findGameObject("Player")->getComponent(ComponentId::Transform));
	_trEnemy = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_audioSource = static_cast<AudioSourceComponent*>(_gameObject->getComponent(ComponentId::AudioSource));
}

void FSMEnemyComponent::update()
{
	double distance = (_trPlayer->getPosition() - _trEnemy->getPosition()).magnitude();
	if (distance <= _distanceAction) {
		actionState();
	}
	else
		startState();
}

void FSMEnemyComponent::startState()
{
}

void FSMEnemyComponent::actionState()
{
	_audioSource->playAudio(1);
	// WARN THE INVISIBLE ENEMY 
	
}
