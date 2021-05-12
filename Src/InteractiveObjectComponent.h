#pragma once

#ifndef INTERACTIVEOBJECTCOMPONENT_H
#define INTERACTIVEOBJECTCOMPONENT_H

#include "Component.h"
#include "UserComponentsIDs.h"
class Logger;

class InteractiveObjectComponent : public Component
{
public:

	
	/// <summary>
	/// Constructor of the class
	/// </summary>
	/// <param name="id">component Id for subclasses</param>
	InteractiveObjectComponent(UserComponentId::UserComponentId id);
	/// <summary>
	/// Destructor of the class
	/// </summary>
	~InteractiveObjectComponent();

	/// <summary>
	/// Notify the player in case the interactive object(this) collide with the player 
	/// </summary>
	void onTrigger(GameObject* other) override;
	void start() override;
	/// <summary>
	/// Make the action when player interacts with the object
	/// </summary>
	virtual void interact();

	/// <summary>
	/// Set the max distance at which the object is no longer interactive
	/// </summary>
	inline void setDistance(double distance) { _distance = distance; }
	/// <summary>
	/// Get the max distance at which the object is no longer interactive
	/// </summary>
	inline double getDistance() { return _distance; }
private:
	Logger* _log;
	double _distance;

};

#endif // !INTERACTIVEOBJECTCOMPONENT_H