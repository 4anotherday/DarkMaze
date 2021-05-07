#pragma once
#include "Component.h"
#include "UserComponentsIDs.h"
class DeactivatableObjectComponent :
	public Component
{
public:
	DeactivatableObjectComponent(UserComponentId::UserComponentId id = UserComponentId::DeactivableObjectCompoent);
	/// <summary>
	/// get whether the object is active or not
	/// </summary>
	/// <returns>true if the object is active, false if not</returns>
	inline bool getActive() { return _active; }

	/// <summary>
	/// Activates or deactivates the object
	/// </summary>
	/// <param name="active">true activates the object, false deactivates the object</param>
	void setActive(bool active);
	virtual void onEnable(){}
	virtual void onDisable(){}
protected:
	bool _active;

};

