#include "ObjectDeactivatorComponent.h"
#include "includeLUA.h"
#include "Engine.h"
#include "TrapComponent.h"
#include "GameObject.h"
#include "Exceptions.h"
#include "AudioSourceComponent.h"

ADD_COMPONENT(ObjectDeactivatorComponent)

ObjectDeactivatorComponent::ObjectDeactivatorComponent() :InteractiveObjectComponent(UserComponentId::ObjectDeactivatorComponent), _trap(nullptr)
{
}

ObjectDeactivatorComponent::~ObjectDeactivatorComponent()
{
}

void ObjectDeactivatorComponent::awake(luabridge::LuaRef& data)
{
	if (LUAFIELDEXIST(ObjName))
		_deactivatableName = GETLUASTRINGFIELD(ObjName);
	else throw ComponentException("trap name not found");
}

void ObjectDeactivatorComponent::start()
{
	InteractiveObjectComponent::start();
	GameObject* go = Engine::getInstance()->findGameObject(_deactivatableName);
	_audio = static_cast<AudioSourceComponent*>(_gameObject->getComponent(ComponentId::AudioSource));
	if (go == nullptr)
		throw NullptrObjectException("trap not found");
	_trap = static_cast<TrapComponent*>(go->getComponent(UserComponentId::TrapComponent));
	if (_trap == nullptr)
		throw ComponentException("TrapComponent not found in an object");
}

void ObjectDeactivatorComponent::interact()
{
	if (Engine::getInstance()->findGameObject(_deactivatableName) != nullptr)
		_trap->defuse();
	_audio->playAudio(0);
	Engine::getInstance()->remGameObject(_gameObject);
}