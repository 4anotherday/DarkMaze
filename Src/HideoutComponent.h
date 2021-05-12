#pragma once
#include "Component.h"
class PlayerVisibilityComponent;
class Transform;
class RenderObjectComponent;
class Logger;
class HideoutComponent :
	public Component
{
public:
	HideoutComponent();
	~HideoutComponent();

	virtual void awake(luabridge::LuaRef& data) override;
	virtual void start() override;
	virtual void update() override;
	virtual void onTrigger(GameObject* other) override;


private:
	Transform* _playerTransform;
	Transform* _myTransform;
	PlayerVisibilityComponent* _visibility;
	RenderObjectComponent* _render;
	Logger* _log;

	float _alpha;
	std::string _playerName;
	float _distance;
};

