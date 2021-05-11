#include "PlayerInteractiveComponent.h"
#include "InteractiveObjectComponent.h"
#include "UserComponentsIDs.h"
#include "ComponentIDs.h"
#include "KeyboardInput.h"
#include "GameObject.h"
#include "Transform.h"

ADD_COMPONENT(PlayerInteractiveComponent)

PlayerInteractiveComponent::PlayerInteractiveComponent() :Component(UserComponentId::PlayerInteractiveComponent), _objectToInteract(nullptr),
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
	if (_keyboard->isKeyJustDown(_key) && _objectToInteract != nullptr && _isStillTrigger()) {
		
			_objectToInteract->interact();
			_objectToInteract = nullptr;
	}
}

void PlayerInteractiveComponent::setObject(InteractiveObjectComponent* ob)
{
	if (ob != nullptr)
		_objectToInteract = ob;
}

bool PlayerInteractiveComponent::_isStillTrigger()
{
	//Get the transform of the interactive object
	GameObject* gIntObject = _objectToInteract->getGameObject();
	Transform* trIntObject = static_cast<Transform*>(gIntObject->getComponent(ComponentId::Transform));
	
	//Set an imaginary position at same height than the player in order to do the correct calculations
	Vector3 auxPos = trIntObject->getPosition();
	auxPos.set(auxPos.getX(), _transform->getPosition().getY(), auxPos.getZ());
	//Get the distance between the player and the object
	double distance = (auxPos - _transform->getPosition()).magnitude();
	//If is still trigger
	if (distance <= _objectToInteract->getDistance()) return true;
	//If not dereference the object
	//_objectToInteract = nullptr;
	return false;
}
