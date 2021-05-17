#include "GameManagerComponent.h"
#include "MotorAudio/AudioEngine.h"
#include "AudioSourceComponent.h"
#include "includeLUA.h"
#include "UserComponentsIDs.h"
#include "GameObject.h"
#include "Engine.h"
#include "KeyboardInput.h"
#include "MouseInput.h"
#include "AudioSourceComponent.h"

ADD_COMPONENT(GameManagerComponent)

GameManagerComponent::GameManagerComponent() : Component(UserComponentId::GameManagerComponent),_level(1), _maxLevel(0), _keyboard(nullptr)
{
}
void GameManagerComponent::awake(luabridge::LuaRef& data)
{
	if (LUAFIELDEXIST(Level)) _level = GETLUAFIELD(Level, int);
	if (LUAFIELDEXIST(MaxLevel)) _maxLevel = GETLUAFIELD(MaxLevel, int);
}

void GameManagerComponent::start()
{
	_keyboard = KeyBoardInput::getInstance();
}

void GameManagerComponent::update()
{
	if (_keyboard->isKeyJustDown(KeyCode::KEYCODE_ESCAPE)) 
		toMenu();
}

void GameManagerComponent::nextLevel()
{
	_level++;
	if (_level < _maxLevel)
		Engine::getInstance()->changeScene("nivel" + std::to_string(_level) + ".lua");
	else {
		toMenu();
		throw "Last level already reached, cannot load next level";
	}

}

void GameManagerComponent::toMenu()
{
	MouseInput::getInstance()->setMouseRelativeMode(false);
	Engine::getInstance()->changeScene("menu.lua");

	GETCOMPONENT(AudioSourceComponent, ComponentId::AudioSource)->playAudio(0);
	GETCOMPONENT(AudioSourceComponent, ComponentId::AudioSource)->setVolumeChannel(0.1, 0);
}


