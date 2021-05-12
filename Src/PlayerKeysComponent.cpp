#include "UserComponentsIDs.h"
#include "PlayerKeysComponent.h"
#include "Engine.h"
#include "GameObject.h"

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
}

void PlayerKeysComponent::spendKey()
{
	_nKeys--;
	if (_nKeys <= 0) _nKeys = 0;
}
