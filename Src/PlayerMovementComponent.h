#pragma once
#ifndef _PLAYER_MOVEMENT_COMPONENT_
#define _PLAYER_MOVEMENT_COMPONENT_

#include "Component.h"
#include "KeyCodes.h"

class GameObject;
class RigidBodyComponent;
class Transform;
class BoxColliderComponent;
class CameraComponent;
class EngineTime;
class KeyBoardInput;
class MouseInput;

class PlayerMovementComponent : public Component {
public:
	PlayerMovementComponent() : PlayerMovementComponent(nullptr) {}
	PlayerMovementComponent(GameObject* gameObject);

	void awake(luabridge::LuaRef& data) override;

	void update() override;
private:

	/// <summary>
	/// Moves the camera orientation
	/// </summary>
	void moveCameraWithMouse(const float deltaTime);
	
	/// <summary>
	/// Moves the player 
	/// </summary>
	/// <param name="deltaTime"></param>
	void manageMovement(const float deltaTime);

	/// <summary>
	/// Manages if the player is crouching, and moves the camera and hitbox accordingly
	/// </summary>
	void manageCrouching();

	Transform* _tr;
	RigidBodyComponent* _rb;
	CameraComponent* _camera;
	BoxColliderComponent* _collider;

	EngineTime* _time;
	KeyBoardInput* _keyboard;
	MouseInput* _mouse;

	float _cameraSpeed;

	KeyCode _keyForward, _keyLeft, _keyRight, _keyBackward, _keyCrouch;
	float _speedForward, _speedSideways, _speedBackwards, _slowCrouching;
	float _playerHeight;

	bool _crouching;
};

#endif // !_PLAYER_MOVEMENT_COMPONENT_
