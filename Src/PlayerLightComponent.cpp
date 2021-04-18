#include "PlayerLightComponent.h"
#include "UserComponentsIDs.h"
#include "LightComponent.h"
#include "Transform.h"
#include "GameObject.h"

PlayerLightComponent::PlayerLightComponent(GameObject* go) : Component(UserComponentId::PlayerLightComponent),
	_playerLight(nullptr)
{
	_playerLight = static_cast<LightComponent*>(go->getComponent(ComponentId::LightComponent));
	_transform = static_cast<Transform*>(go->getComponent(ComponentId::Transform));

	//Set light position to player position
	_playerLight->setPosition(_transform->getPosition().getX(), _transform->getPosition().getY(), _transform->getPosition().getZ());
	//Set light type as Point light
	_playerLight->setType(Light::LightType::POINT);
}

PlayerLightComponent::~PlayerLightComponent()
{
}

void PlayerLightComponent::update()
{
	//Set light position to player position
	_playerLight->setPosition(_transform->getPosition().getX(), _transform->getPosition().getY(), _transform->getPosition().getZ());
}
