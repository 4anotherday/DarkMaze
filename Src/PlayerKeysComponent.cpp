#include "UserComponentsIDs.h"
#include "PlayerKeysComponent.h"
#include "Engine.h"
#include "GameObject.h"
#include "UIManagerComponent.h"

ADD_COMPONENT(PlayerKeysComponent)

PlayerKeysComponent::PlayerKeysComponent() : Component(UserComponentId::PlayerKeysComponent), _nKeys(0)
{
}

PlayerKeysComponent::~PlayerKeysComponent()
{
}

void PlayerKeysComponent::addKey()
{
	_nKeys++;
	GETCOMPONENT(UIManagerComponent, UserComponentId::UIManagerComponent)->showKey();
}

void PlayerKeysComponent::spendKey()
{
	_nKeys--;
	if (_nKeys <= 0) {
		_nKeys = 0;
		GETCOMPONENT(UIManagerComponent, UserComponentId::UIManagerComponent)->hideKey();
	}
}
