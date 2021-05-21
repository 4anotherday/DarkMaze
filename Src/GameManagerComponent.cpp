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

GameManagerComponent::GameManagerComponent() : Component(UserComponentId::GameManagerComponent), _keyboard(nullptr)
{

}

GameManagerComponent::~GameManagerComponent()
{
}

void GameManagerComponent::start()
{
	_keyboard = KeyBoardInput::getInstance();
	Engine::getInstance()->setViewportColour(0, 0, 0);
}

void GameManagerComponent::update()
{
	if (_keyboard->isKeyJustDown(KeyCode::KEYCODE_ESCAPE)) 
		toMenu();
	if (_keyboard->isKeyJustDown(KeyCode::KEYCODE_F)) {
		Engine::getInstance()->setWindowFullScreen();
	}
}

void GameManagerComponent::toMenu()
{
	MouseInput::getInstance()->setMouseRelativeMode(false);
	GETCOMPONENT(AudioSourceComponent, ComponentId::AudioSource)->setAudioLoop(0, -1);
	GETCOMPONENT(AudioSourceComponent, ComponentId::AudioSource)->playAudio(0);
	GETCOMPONENT(AudioSourceComponent, ComponentId::AudioSource)->setVolumeChannel(0.1, 0);
	Engine::getInstance()->changeScene("menu.lua");
}


