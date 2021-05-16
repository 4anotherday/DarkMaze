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
#include "includeLUA.h"

ADD_COMPONENT(PlayerMovementComponent)

PlayerMovementComponent::PlayerMovementComponent(GameObject* gameObject): Component(UserComponentId::PlayerMovementComponent, gameObject), 
	_tr(nullptr), _rb(nullptr), _time(EngineTime::getInstance()), _keyboard(KeyBoardInput::getInstance()), _mouse(MouseInput::getInstance()),
	_cameraSpeed(10.0f), _cam(nullptr),
	_keyForward(KeyCode::KEYCODE_W), _keyLeft(KeyCode::KEYCODE_A), _keyRight(KeyCode::KEYCODE_D), _keyBackward(KeyCode::KEYCODE_S), _keyCrouch(KeyCode::KEYCODE_LCTRL),
	_speedForward(550), _speedSideways(240), _speedBackwards(250), _slowCrouching(0.1f), _playerHeight(2.0f),
	_crouching(false)
{
}

void PlayerMovementComponent::awake(luabridge::LuaRef& data)
{
	//Default values 
	_speedForward = 80;	_speedSideways = 60;	_speedBackwards = 60; _slowCrouching = 0.3; _playerHeight = 2; _cameraSpeed = 5;
	//Lua values if exist
	if (LUAFIELDEXIST(SpeedForward))
		_speedForward = GETLUAFIELD(SpeedForward,float);

	if (LUAFIELDEXIST(SpeedSideWays))
		_speedSideways = GETLUAFIELD(SpeedSideWays, float);

	if (LUAFIELDEXIST(SpeedBackwards))
		_speedBackwards = GETLUAFIELD(SpeedBackwards,float);

	if (LUAFIELDEXIST(SlowCrouching))
		_slowCrouching = GETLUAFIELD(SlowCrouching,float);
	
	if (LUAFIELDEXIST(PlayerHeight))
		_playerHeight = GETLUAFIELD(PlayerHeight,float) / 2;

	if (LUAFIELDEXIST(CameraSpeed))
		_cameraSpeed= GETLUAFIELD(CameraSpeed,float);
}

void PlayerMovementComponent::start()
{
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	//_rb = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
	_cam = static_cast<CameraComponent*>(_gameObject->getComponent(ComponentId::Camera));
	//_rb->setGravity(false);
	//_mouse->setMouseRelativeMode(true);
}

void PlayerMovementComponent::update()
{
	float deltaTime = _time->deltaTime();

	//moveCameraWithMouse(deltaTime);

	//manageCrouching();

	manageMovement(deltaTime);
}

void PlayerMovementComponent::moveCameraWithMouse(const float deltaTime)
{
	double deltaHorizontal = 0, deltaVertical = 0;
	deltaHorizontal = -_mouse->getMouseDelta()[0];
	deltaVertical = -_mouse->getMouseDelta()[1];

	double pitch = 0, yaw = 0;
	Vector3 orientation = _cam->getOrientation();

	//Limit the pitch angle
	float newPitch = orientation.getX() + deltaVertical * _cameraSpeed * deltaTime;
	if (newPitch < 85.0f && deltaVertical > 0 || newPitch > -85.0f && deltaVertical < 0) {
		orientation.setX(newPitch);
	}
	yaw = deltaHorizontal * _cameraSpeed * deltaTime;
	orientation.setY(_cam->getOrientation().getY() + yaw);
	
	_cam->setOrientation(orientation.getX() * PI / 180, orientation.getY() * PI / 180, 0);

	double y = _tr->getRotation().getY() - yaw;
	_tr->setRotation(Vector3(_tr->getRotation().getX(), y, 0));
}

void PlayerMovementComponent::manageMovement(const float deltaTime)
{
	//Vector3 velocity = Vector3(0, 0, -1);
	//Vector3 direction = _tr->getForward();
	//direction.normalize();
	//direction.setY(0);
	//Vector3 rightVector = { direction.getZ(), 0, -direction.getX() };
	//rightVector.normalize();

	//Vector3 vel;

	////Front and back movement
	//if (_keyboard->isKeyDown(_keyForward)) {
	//	direction = direction * (_speedForward);
	//}
	//else if (_keyboard->isKeyDown(_keyBackward)) {
	//	direction = direction * (_speedBackwards * -1.0);
	//}
	////Sideways movement
	//if (_keyboard->isKeyDown(_keyRight)) {
	//	direction = direction + (rightVector * _speedSideways * -1);
	//}
	//else if (_keyboard->isKeyDown(_keyLeft)) {
	//	direction = direction + (rightVector *  _speedSideways);
	//}

	//if (_crouching)
	//	direction = direction * _slowCrouching;

	//direction = direction * deltaTime;

	//_rb->setLinearVelocity(direction);

	Vector3 direction = _tr->getPosition();

	//Front and back movement
	if (_keyboard->isKeyDown(_keyForward)) {
		direction.setZ(direction.getZ() - 0.5);
	}
	else if (_keyboard->isKeyDown(_keyBackward)) {
		direction.setZ(direction.getZ() + 0.5);
	}
	//Sideways movement
	if (_keyboard->isKeyDown(_keyRight)) {
		direction.setX(direction.getX() + 0.5);
	}
	else if (_keyboard->isKeyDown(_keyLeft)) {
		direction.setX(direction.getX() - 0.5);
	}

	_tr->setPosition(direction);

}

void PlayerMovementComponent::manageCrouching()
{
	if (_keyboard->isKeyJustDown(_keyCrouch)) {
		_crouching = true;
		//Move camera and make smaller the collider
		_tr->setPosition(Vector3(_tr->getPosition().getX(), _playerHeight / 2, _tr->getPosition().getZ()));
		_rb->setScale(Vector3(0.5, _playerHeight / 2, 0.5));
	}
	else if (_keyboard->isKeyJustUp(_keyCrouch)) {
		_crouching = false;
		//Move camerea and restore collider
		_tr->setPosition(Vector3(_tr->getPosition().getX(), _playerHeight, _tr->getPosition().getZ()));
		_rb->setScale(Vector3(1, _playerHeight, 1));
	}
}
