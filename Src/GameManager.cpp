#include "GameManager.h"
#include "MotorAudio/AudioEngine.h"
#include "AudioSourceComponent.h"
std::unique_ptr<GameManager> GameManager::instance = nullptr;

GameManager::GameManager() :_level(1), _maxLevel(0), _alredyInitialized(false)
{
}
bool GameManager::init(int maxLevel)
{
	if (_alredyInitialized) {
		Logger::getInstance()->log("GameManagerclass is already initialized", Logger::Level::WARN);
		return false;
	}
	_maxLevel = maxLevel;
	_alredyInitialized = true;
	return true;

}
GameManager* GameManager::getInstance()
{
	return instance.get();

}

void GameManager::CreateInstance()
{
	if (instance.get() == nullptr) {
		instance.reset(new GameManager());
	}
	else {
		Logger::getInstance()->log("Trying to create GameManager instance and it already exist", Logger::Level::WARN);
	}
}

void GameManager::nextLevel()
{
	_level++;
	if (_level < _maxLevel)
		Engine::getInstance()->changeScene("nivel" + std::to_string(_level) + ".lua");
	else throw LevelException("Last level already reached, cannot load next level");

}

void GameManager::resetLevel()
{
	Engine::getInstance()->changeScene("nivel" + std::to_string(_level) + ".lua");
}


