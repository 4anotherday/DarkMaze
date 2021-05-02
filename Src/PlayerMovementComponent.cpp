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
	_speedForward(10), _speedSideways(5), _speedBackwards(5), _slowCrouching(0.5f), _playerHeight(2.0f),
	_crouching(false)
{
}

void PlayerMovementComponent::awake(luabridge::LuaRef& data)
{
	//Default values 
	_speedForward = 5;	_speedSideways = 5;	_speedBackwards = 5; _slowCrouching = 3; _playerHeight = 10;
	//Lua values if exist
	if (LUAFIELDEXIST("SpeedForward"))
		_speedForward = data["SpeedForward"].cast<float>();

	if (LUAFIELDEXIST("SpeedSideWays"))
		_speedSideways = data["SpeedSideWays"].cast<float>();

	if (LUAFIELDEXIST("SpeedBackwards"))
		_speedBackwards = data["SpeedBackwards"].cast<float>();

	if (LUAFIELDEXIST("SlowCrouching"))
		_slowCrouching = data["SlowCrouching"].cast<float>();
	
	if (LUAFIELDEXIST("PlayerHeight"))
		_slowCrouching = data["PlayerHeight"].cast<float>();
}

void PlayerMovementComponent::start()
{
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_rb = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
	_cam = static_cast<CameraComponent*>(_gameObject->getComponent(ComponentId::Camera));

	_mouse->setMouseRelativeMode(true);
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

	double pitch = 0, yaw = 0;
	//Limit the pitch angle
	if (abs(_tr->getRotation().getX() + deltaY * _cameraSpeed * deltaTime) < 45.0f) {
		pitch = deltaY * _cameraSpeed * deltaTime;
		_cam->pitchDegrees(-pitch, false);
	}
	yaw = deltaX * _cameraSpeed * deltaTime;
	_cam->yawDegrees(-yaw, true);

	double x = _tr->getRotation().getX() + pitch;
	double y = _tr->getRotation().getY() + yaw;
	_tr->setRotation(Vector3(x, y, 0));
}

void PlayerMovementComponent::manageMovement(const float deltaTime)
{
	//Vector3 velocity = Vector3(0, 0, -1);
	Vector3 velocity = _tr->getForward();
	velocity.normalize();
	Vector3 rightVector = { velocity.getZ(), 0, -velocity.getX() };
	rightVector.normalize();

	std::cout << "---------------------\n";
	std::cout << velocity.getX() << " " << velocity.getY() << " " << velocity.getZ() << "\n";

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
		_tr->setPosition(Vector3(_tr->getPosition().getX(), _playerHeight / 2, _tr->getPosition().getZ()));
		_rb->setScale(Vector3(1, _playerHeight / 2, 1));
	}
	else if (_keyboard->isKeyJustUp(_keyCrouch)) {
		_crouching = false;
		//Move camerea and restore collider
		_tr->setPosition(Vector3(_tr->getPosition().getX(), _playerHeight, _tr->getPosition().getZ()));
		_rb->setScale(Vector3(1, _playerHeight, 1));
	}
}
