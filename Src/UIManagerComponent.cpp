#include "UIManagerComponent.h"
#include "UserComponentsIDs.h"
#include "includeLUA.h"
#include "OverlayElementMngr.h"

ADD_COMPONENT(UIManagerComponent)

UIManagerComponent::UIManagerComponent() : Component(UserComponentId::UIManagerComponent), _keySprite(nullptr)
{
}

UIManagerComponent::~UIManagerComponent()
{
}

void UIManagerComponent::start()
{
	_keySprite = new OverlayElementMngr("GameUI/KeySprite");
	_keySprite->setEnabled(false);
}

void UIManagerComponent::showKey()
{
	_keySprite->setEnabled(true);
}

void UIManagerComponent::hideKey()
{
	_keySprite->setEnabled(false);
}
