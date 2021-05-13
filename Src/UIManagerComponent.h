#pragma once
#ifndef UIMANAGERCOMPONENT_H
#define UIMANAGERCOMPONENT_H

#include "Component.h"

class OverlayElementMngr;

class UIManagerComponent : public Component {
public:
	UIManagerComponent();
	~UIManagerComponent();

	void start() override;

	/// <summary>
	/// Shows the key sprite in the GUI
	/// </summary>
	void showKey();

	/// <summary>
	/// Hides the key sprite in the GUI
	/// </summary>
	void hideKey();
private:
	OverlayElementMngr* _keySprite;
};

#endif // !UIMANAGERCOMPONENT_H
