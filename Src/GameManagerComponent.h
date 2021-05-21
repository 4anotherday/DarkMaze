#pragma once
#include "Component.h"
class KeyBoardInput;

class GameManagerComponent : public Component
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	GameManagerComponent();
	/// <summary>
	/// Destructor of the class
	/// </summary>
	~GameManagerComponent();

	/// <summary>
	/// Initializes the component, called once at the start of the execution
	/// </summary>
	void start() override;

	/// <summary>
	/// Checks the distance between 
	/// </summary>
	void update() override;

	/// <summary>
	/// Goes to the main menu
	/// </summary>
	void toMenu();


private:
	KeyBoardInput* _keyboard;
};

