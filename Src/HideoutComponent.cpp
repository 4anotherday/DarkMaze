#include "HideoutComponent.h"
#include "HealthComponent.h"
#include "ComponentIDs.h"
#include "includeLUA.h"
#include "Transform.h"
#include "PlayerVisibilityComponent.h"
#include "UserComponentsIDs.h"
#include "GameObject.h"
#include "RenderObjectComponent.h"
#include "ColliderComponent.h"
#include "Engine.h"
#include "Logger.h"

ADD_COMPONENT(HideoutComponent)

HideoutComponent::HideoutComponent() :Component(UserComponentId::HideoutComponent), _log(nullptr), _playerTransform(nullptr), _myTransform(nullptr), _visibility(nullptr), _playerName("Player")
, _render(nullptr), _alpha(.5f), _distance(1) {
}
HideoutComponent::~HideoutComponent()
{
}

void HideoutComponent::awake(luabridge::LuaRef& data)
{
	if (LUAFIELDEXIST(PlayerName))
		_playerName = GETLUASTRINGFIELD(PlayerName);
	if (LUAFIELDEXIST(Alpha))
		_alpha = GETLUAFIELD(Alpha, float);
}

void HideoutComponent::start()
{
	_log = Logger::getInstance();
	GameObject* go = Engine::getInstance()->findGameObject(_playerName);
	if (go != nullptr)
	{
		_visibility = static_cast<PlayerVisibilityComponent*>(go->getComponent(UserComponentId::PlayerVisibilityComponent));
		if (_visibility == nullptr)
			throw "Player doesn't have PlayerVisibilityComponent";
		_playerTransform = static_cast<Transform*>(go->getComponent(ComponentId::Transform));
		if (_playerTransform == nullptr)
			throw "Player doesn't have Transform";
		_myTransform = GETCOMPONENT(Transform, ComponentId::Transform);
		if (_myTransform == nullptr)
			throw "Hideout doesn't have Transform";
		SphereColliderComponent* col = GETCOMPONENT(SphereColliderComponent, ComponentId::SphereCollider);
		if (col != nullptr)
			_distance = 2 * col->getRadius();
		else if (_log != nullptr) _log->log("Hideout doesn't have SphereColliderComponent", Logger::Level::WARN);
		_render = GETCOMPONENT(RenderObjectComponent, ComponentId::RenderObject);
		if (_render == nullptr && _log != nullptr)
			_log->log("Hideout doesn't have RenderObjectComponent, transparencies won't work", Logger::Level::WARN);
	}
	else throw "Player GameObject not found";
}

void HideoutComponent::update()
{
	if (!_visibility->getVisible()) {

		Vector3 pos(_myTransform->getPosition().getX(), _playerTransform->getPosition().getY(), _myTransform->getPosition().getZ());
		float distance = std::abs((pos - _playerTransform->getPosition()).magnitude());
		if (distance >= _distance) {

			_visibility->setVisible(true);
			_render->setAlpha(1.0f);
		}
	}

}

void HideoutComponent::onTrigger(GameObject* other)
{
	_visibility->setVisible(false);
	_render->setAlpha(_alpha);

}
