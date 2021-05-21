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
	/// Triggered when player enables the trap
	/// </summary>
	void onEnable();
	/// <summary>
	/// Triggered when player disables the trap
	/// </summary>
	void onDisable();

	/// <summary>
	/// kills the player if the trap is active
	/// </summary>
	/// <param name="other">the collision gameObject</param>
	virtual void onTrigger(GameObject* other)override;
	/// <summary>
	/// get whether the trap is active or not
	/// </summary>
	/// <returns>true if the trap is active, false if not</returns>
	inline bool getActive() { return _active; }

	/// <summary>
	/// Activates or deactivates the trap
	/// </summary>
	/// <param name="active">true activates the trap, false deactivates the trap</param>
	void setActive(bool active);

private:
	RenderObjectComponent* _renderObject;
	AudioSourceComponent* _audio;
	Logger* _log;
	bool _active;
	std::string _enabledMaterial;
	std::string _disabledMaterial;
};
#endif // !TRAPCOMPONENT_H
