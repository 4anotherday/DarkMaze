#pragma once

#ifndef PLAYERLOOKENEMYGLITCHCOMPONENT_H
#define PLAYERLOOKENEMYGLITCHCOMPONENT_H

#include "Component.h"
#include "Vector3.h"
class GameObject;
class CameraComponent;
class Transform;

class PlayerLookEnemyGlitchComponent : public Component
{
public:

	PlayerLookEnemyGlitchComponent();
	~PlayerLookEnemyGlitchComponent();

	void awake(luabridge::LuaRef& data) override;

	void start() override;

	void update() override;
	
private:

	void changeWeakComp(bool enable);
	void changeStrongComp(bool enable);

	CameraComponent* _camera;
	Transform* _myTransform, *_enemyTransform;

	float _sightDistanceWeak, _angleWeakRange;
	float _sightDistanceStrong, _angleStrongRange;

	bool _weakComp, _strongComp;
};

#endif // !PLAYERLOOKENEMYGLITCHCOMPONENT_H