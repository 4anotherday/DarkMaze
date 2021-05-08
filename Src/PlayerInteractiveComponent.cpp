#include "PlayerInteractiveComponent.h"
#include "InteractiveObjectComponent.h"
#include "UserComponentsIDs.h"
#include "ComponentIDs.h"
#include "KeyboardInput.h"
#include "GameObject.h"
#include "Transform.h"

ADD_COMPONENT(PlayerInteractiveComponent)

PlayerInteractiveComponent::PlayerInteractiveComponent():Component(UserComponentId::PlayerInteractiveComponent), _objectToInteract(nullptr),
_keyboard(KeyBoardInput::getInstance()), _transform(nullptr), _key(KeyCode::KEYCODE_E)
{
}

PlayerInteractiveComponent::~PlayerInteractiveComponent()
{
}

void PlayerInteractiveComponent::start()
{
	_transform = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
}

void PlayerInteractiveComponent::update()
{
	if (_keyboard->isKeyJustDown(_key) && _objectToInteract != nullptr && _isStillTrigger()) 
	{
		_objectToInteract->interact();
	}
}

void PlayerInteractiveComponent::setObject(InteractiveObjectComponent* ob)
{
	_objectToInteract = ob;
}

bool PlayerInteractiveComponent::_isStillTrigger()
{
	//Get the transform of the interactive object
	GameObject* gIntObject = _objectToInteract->getGameObject();
	Transform* trIntObject = static_cast<Transform*>(gIntObject->getComponent(ComponentId::Transform));
	//Get the distance between the player and the object
	double distance = (trIntObject->getPosition() - _transform->getPosition()).magnitude();
	//If is still trigger
	if (distance <= _objectToInteract->getDistance()) return true;
	//If not dereference the object
	_objectToInteract = nullptr;
	return false;
}
