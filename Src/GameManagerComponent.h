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
	/// <param name="cause">0 if defeat, 1 if victory, other if exit</param>
	void toMenu(int cause);


private:
	KeyBoardInput* _keyboard;
};

