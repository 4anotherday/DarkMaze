#include "PlayerLookEnemyGlitchComponent.h"
#include "UserComponentsIDs.h"
#include "Transform.h"
#include "GameObject.h"
#include "CameraComponent.h"
#include "Engine.h"
#include "RayCast.h"
#include "includeLUA.h"

ADD_COMPONENT(PlayerLookEnemyGlitchComponent)

PlayerLookEnemyGlitchComponent::PlayerLookEnemyGlitchComponent() : Component(UserComponentId::PlayerLookEnemyGlitchComponent),
	_camera(nullptr), _myTransform(nullptr), _enemyTransform(nullptr), 
	_sightDistanceWeak(20.0), _angleWeakRange(20.0), _sightDistanceStrong(8.0), _angleStrongRange(60.0),
	_weakComp(false), _strongComp(false)
{	
}

PlayerLookEnemyGlitchComponent::~PlayerLookEnemyGlitchComponent()
{
}

void PlayerLookEnemyGlitchComponent::awake(luabridge::LuaRef& data)
{
	if (LUAFIELDEXIST(SightDistanceWeak))		_sightDistanceWeak =	GETLUAFIELD(SightDistanceWeak, double);
	if (LUAFIELDEXIST(SightDistanceStrong))		_sightDistanceStrong =	GETLUAFIELD(SightDistanceStrong, double);

	if (LUAFIELDEXIST(AngleWeakRange))			_angleWeakRange =		GETLUAFIELD(AngleWeakRange, double);
	if (LUAFIELDEXIST(AngleStrongRange))		_angleStrongRange =		GETLUAFIELD(AngleStrongRange, double);
}

void PlayerLookEnemyGlitchComponent::start()
{
	_camera = GETCOMPONENT(CameraComponent, ComponentId::Camera);

	_myTransform = GETCOMPONENT(Transform, ComponentId::Transform);
	_enemyTransform = static_cast<Transform*>(Engine::getInstance()->findGameObject("InvisibleEnemy")->getComponent(ComponentId::Transform));
}

void PlayerLookEnemyGlitchComponent::update()
{
	const Vector3& enemyPos = _enemyTransform->getPosition();
	const Vector3& myPos = _myTransform->getPosition();

	Vector3 dir = (enemyPos - myPos).normalize();
	double distance = (enemyPos - myPos).magnitude();

	//If ray doesnt hit anything static, that means we have direct sight towards the player
	RayCast::RayCastHit ray = RayCast(myPos, dir, distance, RayCast::Type::Static).getRayCastInformation();
	if (!ray.hit) {
		Vector3 forward = _myTransform->getForward();
		if (distance < _sightDistanceStrong && forward.angleDegreesBetweenVector(dir) < _angleStrongRange) {
			changeWeakComp(false);
			changeStrongComp(true);
		}
		else if (distance < _sightDistanceWeak && forward.angleDegreesBetweenVector(dir) < _angleWeakRange) {
			changeWeakComp(true);
			changeStrongComp(false);
		}
		else {
			changeWeakComp(false);
			changeStrongComp(false);
		}
	}
}

void PlayerLookEnemyGlitchComponent::changeWeakComp(bool enable)
{
	if (_weakComp != enable) {
		_camera->setCompositor("JugadorVisionWeak", enable);
		_weakComp = enable;
	}
}

void PlayerLookEnemyGlitchComponent::changeStrongComp(bool enable)
{
	if (_strongComp != enable) {
		_camera->setCompositor("JugadorVisionStrong", enable);
		_strongComp = enable;
	}
}
