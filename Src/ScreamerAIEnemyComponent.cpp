#include "ScreamerAIEnemyComponent.h"
#include "UserComponentsIDs.h"
#include "Transform.h"
#include "AudioSourceComponent.h"
#include "GameObject.h"
#include "Engine.h"
#include "RigidBodyComponent.h"

ADD_COMPONENT(ScreamerAIEnemyComponent)

ScreamerAIEnemyComponent::ScreamerAIEnemyComponent() : Component(UserComponentId::ScreamerAIEnemyComponent), _rangeToAttack(),
 _trPlayer(nullptr), _trEnemy(nullptr), _move(false), _audioSource(nullptr), _rigidBodyEnemy(nullptr)
{
}

ScreamerAIEnemyComponent::~ScreamerAIEnemyComponent()
{
}

void ScreamerAIEnemyComponent::start()
{
	_rigidBodyEnemy = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
	_trPlayer = static_cast<Transform*>(Engine::getInstance()->findGameObject("Player")->getComponent(ComponentId::Transform));
	_trEnemy = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_audioSource = static_cast<AudioSourceComponent*>(_gameObject->getComponent(ComponentId::AudioSource));
}

void ScreamerAIEnemyComponent::update()
{
	double distance = (_trPlayer->getPosition() - _trEnemy->getPosition()).magnitude();
	if (distance <= _rangeToAttack) {
		_move = true;	
	}
	else idlestate();

	if (_move) {
		movingState();
		if (distance <= _rangeToAttack / 2) {
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
	_move = true;
	//TODO: Parar audio idle	

	//Raycsast o pathfinding para encontrar el camino al jugador
	Vector3 dir = _trPlayer->getPosition();
	_rigidBodyEnemy->moveTo(dir);
}

void ScreamerAIEnemyComponent::screamingState()
{
	//1 corresponds with attack
	_audioSource->playAudio(1);
	// WARN THE INVISIBLE ENEMY 
}
