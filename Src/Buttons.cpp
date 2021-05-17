#include "Buttons.h"
#include "UserComponentsIDs.h"
#include "includeLUA.h"
#include "Engine.h"
#include "ButtonComponent.h"
#include "GameObject.h"
#include "MouseInput.h"


//-----------------------------------------------PLAY BUTTON-------------------------------------------------------------
ADD_COMPONENT(PlayButtonComponent)

PlayButtonComponent::PlayButtonComponent(): Component(UserComponentId::PlayButtonComponent), _buttonComp(nullptr)
{
}

PlayButtonComponent::~PlayButtonComponent()
{
}

void PlayButtonComponent::start()
{
	_buttonComp = GETCOMPONENT(ButtonComponent, ComponentId::ButtonComponent);
	_buttonComp->setCallBackParam(nullptr);
	_buttonComp->setCallBack(startGame);
}

void PlayButtonComponent::startGame(void* null)
{
	MouseInput::getInstance()->setMouseRelativeMode(true);
	Engine::getInstance()->changeScene("nivel1Test.lua");
}

//-----------------------------------------------QUIT BUTTON-------------------------------------------------------------
ADD_COMPONENT(QuitButtonComponent)

QuitButtonComponent::QuitButtonComponent(): Component(UserComponentId::QuitButtonComponent), _buttonComp(nullptr)
{
}

QuitButtonComponent::~QuitButtonComponent()
{
}

void QuitButtonComponent::start()
{
	_buttonComp = GETCOMPONENT(ButtonComponent, ComponentId::ButtonComponent);
	_buttonComp->setCallBackParam(nullptr);
	_buttonComp->setCallBack(quitGame);
}

void QuitButtonComponent::quitGame(void* player)
{
	Engine::getInstance()->stopExecution();
}
