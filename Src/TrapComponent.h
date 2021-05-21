#pragma once
#ifndef TRAPCOMPONENT_H
#define TRAPCOMPONENT_H
#include "Component.h"
class Logger;
class RenderObjectComponent;
class AudioSourceComponent;
class TrapComponent :
	public Component
{
public:
	TrapComponent();
	~TrapComponent();
	virtual void start() override;
	virtual void awake(luabridge::LuaRef& data) override;

	/// <summary>
	/// kills the player if the trap is active
	/// </summary>
	/// <param name="other">the collision gameObject</param>
	virtual void onTrigger(GameObject* other)override;
	
	/// <summary>
	/// Defuses the trap
	/// </summary>
	/// <returns></returns>
	void defuse();

private:
	RenderObjectComponent* _renderObject;
	AudioSourceComponent* _audio;
	Logger* _log;
	bool _active;
	std::string _enabledMaterial;
	std::string _disabledMaterial;
};
#endif // !TRAPCOMPONENT_H
