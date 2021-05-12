#pragma once
#include "UserComponentsIDs.h"
#include "Component.h"
#include "Engine.h"
#include "Exceptions.h"
class GameManager 
{
public:

    GameManager();
    ~GameManager(){}
    /// <summary>
    /// Returns the instance of GameManager, or nullptr if it doesnt exist yet
    /// </summary>
    static GameManager* getInstance();

	/// <summary>
	/// Creates the GameManager singleton instance if its not already created
	/// </summary>
	static void CreateInstance();

	GameManager& operator=(const GameManager&) = delete;
	GameManager(GameManager& other) = delete;

	/// <summary>
	/// Initialize everything related to the Graphics, Physics and Audio engines
	/// </summary>
	/// <param name="maxLevel">maximun level number</param>
	/// <returns>true on success, false on error</returns>
	bool init(int maxLevel);

	/// <summary>
	/// Loads the next level,if exists
	/// </summary>
	void nextLevel();

	/// <summary>
	/// Reloads the current level
	/// </summary>
	void resetLevel();


private:
	bool _alredyInitialized;
    int _level;
	int _maxLevel;
	static std::unique_ptr<GameManager> instance;

};

