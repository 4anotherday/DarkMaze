#include "PlayerMovementComponent.h"
#include "GameObject.h"
#include "UserComponentsIDs.h"
#include "KeyboardInput.h"
#include "Transform.h"
#include "RigidBodyComponent.h"
#include "CameraComponent.h"
#include "MouseInput.h"
#include "EngineTime.h"

PlayerMovementComponent::PlayerMovementComponent(GameObject* gameObject): Component(UserComponentId::PlayerMovementComponent, gameObject), 
	_tr(nullptr), _rb(nullptr), _camera(nullptr),
	_cameraSpeed(1.0f), _pitchAngle(0.0f),
	_keyForward(KeyCode::KEYCODE_W), _keyLeft(KeyCode::KEYCODE_A), _keyRight(KeyCode::KEYCODE_D), _keyBackward(KeyCode::KEYCODE_S),
	_speedForward(5), _speedSideways(2), _speedBackwards(2), _slowCreeping(0.5f)
{
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_rb = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
	_camera = static_cast<CameraComponent*>(_gameObject->getComponent(ComponentId::Camera));

	//MouseInput::getInstance()->setRelative();
}

void PlayerMovementComponent::update()
{
	float deltaTime = EngineTime::getInstance()->deltaTime();
	
	moveCamera(deltaTime);

	KeyBoardInput* keyBoard = KeyBoardInput::getInstance();
	//Front and back movement
	if (keyBoard->isKeyDown(_keyForward)) {
		//Move player forward
	}
	else if (keyBoard->isKeyDown(_keyBackward)) {
		//Move player backwards
	}

	//Sideways movement
	if (keyBoard->isKeyDown(_keyLeft)) {
		//Move player to the left
	}
	else if (keyBoard->isKeyDown(_keyRight)) {
		//Move player to the right
	}
}

void PlayerMovementComponent::moveCamera(float deltaTime)
{
	MouseInput* mouse = MouseInput::getInstance();

	float deltaX = 0, deltaY = 0;
	//mouse->getRelativeMovement();

	if (abs(_pitchAngle + deltaY * deltaTime) < 89.9f) {
		_camera->pitchDegrees(deltaY * deltaTime);
	}

	_camera->yawDegrees(deltaX * deltaTime);
}
