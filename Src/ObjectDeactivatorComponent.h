#pragma once
#ifndef OBJECT_DEACTIVATOR_COMPONENT
#define OBJECT_DEACTIVATOR_COMPONENT

#include "InteractiveObjectComponent.h"
#include <string>
class TrapComponent;

class ObjectDeactivatorComponent :
	public InteractiveObjectComponent
{
public:
	ObjectDeactivatorComponent();
	~ObjectDeactivatorComponent();
	virtual void awake(luabridge::LuaRef& data) override;
	virtual void start() override;
	/// <summary>
	/// Activates or deactivates an deactivatable object
	/// </summary>
	virtual void interact() override;

private:
	TrapComponent* _trap;
	std::string _deactivatableName;
};

#endif