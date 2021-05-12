#include "PlayerVisibilityComponent.h"
#include "UserComponentsIDs.h"

ADD_COMPONENT(PlayerVisibilityComponent)

PlayerVisibilityComponent::PlayerVisibilityComponent() :Component(UserComponentId::PlayerVisibilityComponent), _visible(true)
{
}

PlayerVisibilityComponent::~PlayerVisibilityComponent()
{
}

void PlayerVisibilityComponent::setVisible(bool vis)
{
	_visible = vis;
}

bool PlayerVisibilityComponent::getVisible()
{
	return _visible;
}
