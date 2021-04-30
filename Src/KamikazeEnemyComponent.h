//https://www.mixamo.com/#/?page=1&query=run&type=Motion%2CMotionPack

#pragma once
#ifndef _KAMIKAZE_ENEMY_COMPONENT_
#define _KAMIKAZE_ENEMY_COMPONENT_

#include "Component.h"

class Transform;
class RigidbodyComponent;
class ColliderComponent;

class KamikazeEnemyComponent : public Component {
public:
	KamikazeEnemyComponent();

	~KamikazeEnemyComponent();

	void awake(luabridge::LuaRef& data) override;

	void start() override;

	void update() override;

private:
	RigidbodyComponent* _rb;
	ColliderComponent* _visionTrigger;

	float visionRange;
};

#endif // !_KAMIKAZE_ENEMY_COMPONENT_
