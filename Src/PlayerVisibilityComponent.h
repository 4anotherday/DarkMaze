#pragma once
#include "Component.h"
class PlayerVisibilityComponent :
    public Component
{
public:
	PlayerVisibilityComponent();
	~PlayerVisibilityComponent();
	/// <summary>
	/// Sets whether the player is visible
	/// </summary>
	/// <param name="vis">True if visible, false if invisible</param>
	void setVisible(bool vis); 

	/// <summary>
	/// Gets whether the player is visible
	/// </summary>
	/// <returns>True if visible, false if invisible</returns>
	bool getVisible();
private:
	bool _visible;

};

