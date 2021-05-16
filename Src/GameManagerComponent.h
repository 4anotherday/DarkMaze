#pragma once
#include "Component.h"
class KeyBoardInput;

class GameManagerComponent : public Component
{
public:

	GameManagerComponent();
    ~GameManagerComponent(){}

	void awake(luabridge::LuaRef& data) override;

	void start() override;

	void update() override;

	/// <summary>
	/// Loads the next level,if exists
	/// </summary>
	void nextLevel();

	/// <summary>
	/// Reloads the current level
	/// </summary>
	void toMenu();


private:
	KeyBoardInput* _keyboard;
    int _level;
	int _maxLevel;

};

