#include "ScreamerAIEnemyComponent.h"
#include "UserComponentsIDs.h"
#include "Transform.h"
#include "AudioSourceComponent.h"
#include "GameObject.h"
#include "Engine.h"
#include "RigidBodyComponent.h"
#include "EngineTime.h"

ADD_COMPONENT(ScreamerAIEnemyComponent)

ScreamerAIEnemyComponent::ScreamerAIEnemyComponent() : Component(UserComponentId::ScreamerAIEnemyComponent), _rangeToAttack(),
 _tranformPlayer(nullptr), _transformEnemy(nullptr), _startToMove(false), _startScream(false), _audioSource(nullptr), _rigidBodyEnemy(nullptr)
{
}

ScreamerAIEnemyComponent::~ScreamerAIEnemyComponent()
{
}

void ScreamerAIEnemyComponent::start()
{
	_rigidBodyEnemy = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
	_tranformPlayer = static_cast<Transform*>(Engine::getInstance()->findGameObject("Player")->getComponent(ComponentId::Transform));
	_transformEnemy = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_audioSource = static_cast<AudioSourceComponent*>(_gameObject->getComponent(ComponentId::AudioSource));
}

void ScreamerAIEnemyComponent::update()
{
	double distance = (_tranformPlayer->getPosition() - _transformEnemy->getPosition()).magnitude();
	if (distance <= _rangeToAttack) {
		_startToMove = true;	
	}
	else idlestate();

	if (_startToMove) {
		movingState();
		if (distance <= _rangeToAttack / 3 && !_startScream) {
			screamingState();
		}
	}
}


void ScreamerAIEnemyComponent::idlestate()
{
	//0 is the audio corresponding to idle
	_audioSource->playAudio(0);
}

void ScreamerAIEnemyComponent::movingState()
{
	_startToMove = true;
	//TODO: Parar audio idle	

	//TODO: Raycast o pathfinding para encontrar el camino al jugador
	Vector3 dir = _tranformPlayer->getPosition();
	_rigidBodyEnemy->moveTo(dir);
}

void ScreamerAIEnemyComponent::screamingState()
{
	//1 corresponds with attack
	_audioSource->playAudio(1);
	_startScream = true;
	// WARN THE INVISIBLE ENEMY 
}
