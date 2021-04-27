#include "PlayerMovementComponent.h"
#include "GameObject.h"
#include "UserComponentsIDs.h"
#include "Transform.h"
#include "RigidBodyComponent.h"
#include "ColliderComponent.h"
#include "CameraComponent.h"
#include "KeyboardInput.h"
#include "MouseInput.h"
#include "EngineTime.h"

PlayerMovementComponent::PlayerMovementComponent(GameObject* gameObject): Component(UserComponentId::PlayerMovementComponent, gameObject), 
	_tr(nullptr), _rb(nullptr), _camera(nullptr), _time(EngineTime::getInstance()), _keyboard(KeyBoardInput::getInstance()), _mouse(MouseInput::getInstance()),
	_cameraSpeed(1.0f),
	_keyForward(KeyCode::KEYCODE_W), _keyLeft(KeyCode::KEYCODE_A), _keyRight(KeyCode::KEYCODE_D), _keyBackward(KeyCode::KEYCODE_S), _keyCrouch(KeyCode::KEYCODE_LCTRL),
	_speedForward(5), _speedSideways(2), _speedBackwards(2), _slowCrouching(0.5f), _playerHeight(2.0f),
	_crouching(false)
{
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_rb = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
	_camera = static_cast<CameraComponent*>(_gameObject->getComponent(ComponentId::Camera));
	_collider = static_cast<BoxColliderComponent*>(_gameObject->getComponent(ComponentId::BoxCollider));

	_mouse->setMouseRelativeMode(true);
}

void PlayerMovementComponent::awake(luabridge::LuaRef& data)
{

}

void PlayerMovementComponent::update()
{
	float deltaTime = _time->deltaTime();
	
	moveCameraWithMouse(deltaTime);

	manageCrouching();

	manageMovement(deltaTime);
}

void PlayerMovementComponent::moveCameraWithMouse(const float deltaTime)
{
	double deltaX = 0, deltaY = 0;
	deltaX = _mouse->getMouseDelta()[0];
	deltaY = _mouse->getMouseDelta()[1];

	//Limit the pitch angle
	if (abs(_camera->getOrientation().getY() + deltaY * _cameraSpeed * deltaTime) < 89.0f) {
		_camera->pitchDegrees(deltaY * _cameraSpeed * deltaTime);
	}

	_camera->yawDegrees(deltaX * _cameraSpeed * deltaTime);
}

void PlayerMovementComponent::manageMovement(const float deltaTime)
{
	Vector3 velocity = _tr->getForward();
	velocity.normalize();
	Vector3 rightVector = { velocity.getZ(), 0, -velocity.getX() };
	rightVector.normalize();

	//Front and back movement
	if (_keyboard->isKeyDown(_keyForward)) {
		velocity = velocity * (_speedForward);
	}
	else if (_keyboard->isKeyDown(_keyBackward)) {
		velocity = velocity * (_speedBackwards * -1.0);
	}
	//Sideways movement
	if (_keyboard->isKeyDown(_keyRight)) {
		velocity = velocity + (rightVector * _speedSideways);
	}
	else if (_keyboard->isKeyDown(_keyLeft)) {
		velocity = velocity + (rightVector * -1.0 * _speedSideways);
	}

	if (_crouching)
		velocity = velocity * _slowCrouching;

	velocity = velocity * deltaTime;

	_rb->addForce(velocity);
}

void PlayerMovementComponent::manageCrouching()
{
	if (_keyboard->isKeyJustDown(_keyCrouch)) {
		_crouching = true;
		//Move camera and make smaller the collider
		_camera->setPosition(_tr->getPosition().getX(), _playerHeight / 2, _tr->getPosition().getZ());
		_collider->setScale(1, _playerHeight / 2, 1);
	}
	else if (_keyboard->isKeyJustUp(_keyCrouch)) {
		_crouching = false;
		//Move camerea and restore collider
		_camera->setPosition(_tr->getPosition().getX(), _playerHeight, _tr->getPosition().getZ());
		_collider->setScale(1, _playerHeight, 1);
	}
}
