#pragma once
#ifndef _PLAYER_MOVEMENT_COMPONENT_
#define _PLAYER_MOVEMENT_COMPONENT_

#include "Component.h"
#include "KeyCodes.h"

class GameObject;
class RigidBodyComponent;
class Transform;

class PlayerMovementComponent : public Component {
public:
	PlayerMovementComponent(GameObject* gameObject);

	void update();
private:
	Transform* _tr;
	RigidBodyComponent* _rb;

	KeyCode _keyForward, _keyLeft, _keyRight, _keyBackward;

	float _speedForward, _speedSideways, _speedBackwards;
};

#endif // !_PLAYER_MOVEMENT_COMPONENT_
