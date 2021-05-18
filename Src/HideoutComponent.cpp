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
, _render(nullptr), _alphaMaterial("Practica1/BushAlpha"), _normalMaterial("Practica1/Bush"), _distance(1) {
}
HideoutComponent::~HideoutComponent()
{
}

void HideoutComponent::awake(luabridge::LuaRef& data)
{
	if (LUAFIELDEXIST(PlayerName))
		_playerName = GETLUASTRINGFIELD(PlayerName);
	if (LUAFIELDEXIST(AlphaMaterial))
		_alphaMaterial = GETLUASTRINGFIELD(AlphaMaterial);
	if (LUAFIELDEXIST(NormalMaterial))
		_normalMaterial = GETLUASTRINGFIELD(NormalMaterial);
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
	std::cout << _myTransform->getPosition().getX() << " " << _myTransform->getPosition().getY() << _myTransform->getPosition().getZ() << '\n';
	std::cout << _playerTransform->getPosition().getX() << " " << _playerTransform->getPosition().getY() << _playerTransform->getPosition().getZ() << '\n';

	if (!_visibility->getVisible()) {

		Vector3 pos(_myTransform->getPosition().getX(), _playerTransform->getPosition().getY(), _myTransform->getPosition().getZ());
		float distance = std::abs((pos - _playerTransform->getPosition()).magnitude());
		//the second check is to avoid other hideouts setting visible the player
		if (distance >= _distance && distance <= 1.1 * _distance) {

			_visibility->setVisible(true);
			_render->setMaterial(_normalMaterial);
		}
	}

}

void HideoutComponent::onTrigger(GameObject* other)
{
	if (other->getComponent(UserComponentId::PlayerVisibilityComponent) != nullptr) {

		_visibility->setVisible(false);
		_render->setMaterial(_alphaMaterial);
	}

}
