#include "PlayerLightComponent.h"
#include "UserComponentsIDs.h"
#include "LightComponent.h"
#include "Transform.h"
#include "GameObject.h"
#include "ListenerComponent.h"

ADD_COMPONENT(PlayerLightComponent)

PlayerLightComponent::PlayerLightComponent() : Component(UserComponentId::PlayerLightComponent),
	_playerLight(nullptr), _transform(nullptr)
{	
}

PlayerLightComponent::~PlayerLightComponent()
{
}

void PlayerLightComponent::awake(luabridge::LuaRef& data)
{
}

void PlayerLightComponent::start()
{
	_playerLight = static_cast<LightComponent*>(_gameObject->getComponent(ComponentId::LightComponent));
	_transform = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));

	//Set light position to player position
	//_playerLight->setPosition(_transform->getPosition().getX(), _transform->getPosition().getY(), _transform->getPosition().getZ());
	//Set light type as Point light
	_playerLight->setType(Light::LightType::POINT); 
}

void PlayerLightComponent::update()
{
	//Set light position to player position
	//_playerLight->setPosition(_transform->getPosition().getX(), _transform->getPosition().getY(), _transform->getPosition().getZ());
}
