#include "PlayerLightComponent.h"
#include "UserComponentsIDs.h"
#include "LightComponent.h"
#include "Transform.h"
#include "GameObject.h"

PlayerLightComponent::PlayerLightComponent(GameObject* go) : Component(UserComponentId::PlayerLightComponent),
	_playerLight(nullptr)
{
	_playerLight = static_cast<LightComponent*>(go->getComponent(ComponentId::LightComponent));
	//WIP
	//Set light position to player position
	//Set light type as Point light
	_transform = static_cast<Transform*>(go->getComponent(ComponentId::Transform));
}

PlayerLightComponent::~PlayerLightComponent()
{
}

void PlayerLightComponent::update()
{
}
