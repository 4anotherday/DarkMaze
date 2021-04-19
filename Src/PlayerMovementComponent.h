#pragma once
#ifndef _PLAYER_MOVEMENT_COMPONENT_
#define _PLAYER_MOVEMENT_COMPONENT_

#include "Component.h"
#include "KeyCodes.h"

class GameObject;
class RigidBodyComponent;
class Transform;
class CameraComponent;

class PlayerMovementComponent : public Component {
public:
	PlayerMovementComponent() : PlayerMovementComponent(nullptr) {}
	PlayerMovementComponent(GameObject* gameObject);

	void update();
private:

	void moveCamera(float deltaTime);

	Transform* _tr;
	RigidBodyComponent* _rb;
	CameraComponent* _camera;

	float _cameraSpeed;
	float _pitchAngle;

	KeyCode _keyForward, _keyLeft, _keyRight, _keyBackward;
	float _speedForward, _speedSideways, _speedBackwards, _slowCreeping;
};

#endif // !_PLAYER_MOVEMENT_COMPONENT_
