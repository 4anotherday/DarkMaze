#include "InvisibleEnemyAIComponent.h"
#include "UserComponentsIDs.h"
#include "Transform.h"
#include "Engine.h"
#include "GameObject.h"

#define CAST_COMPONENT component = static_cast<InvisibleEnemyAIComponent*>(component)

ADD_COMPONENT(InvisibleEnemyAIComponent)

InvisibleEnemyAIComponent::InvisibleEnemyAIComponent() : Component(UserComponentId::InvisibleEnemyAIComponent),
	_transformPlayer(nullptr), _ai(nullptr), _states(), _transitions()
{

}

InvisibleEnemyAIComponent::~InvisibleEnemyAIComponent()
{
	delete _ai; _ai = nullptr;
	for (State* s : _states) {
		delete s; s = nullptr;
	}
	for (Transition* t : _transitions) {
		delete t; t = nullptr;
	}
}

void InvisibleEnemyAIComponent::awake(luabridge::LuaRef& data)
{
	GameObject* player = Engine::getInstance()->findGameObject("player");

	_transformPlayer = GETCOMPONENT(Transform, ComponentId::Transform);

	createFSM(data);
}

void InvisibleEnemyAIComponent::update()
{
	_ai->step();
}

void InvisibleEnemyAIComponent::createFSM(luabridge::LuaRef& data)
{
	_ai = new FSM(this);

	State* find = createState<FindState>();
	State* towardsPlayer = createState<GoTowardsPlayerState>();
	State* attackPlayer = createState<AttackPlayerState>();

	Transition* lostSightTransition = createTransition<LostSightTransition>();
	Transition* gainSightTransition = createTransition<GainSightTransition>();
	Transition* inRangeTransition = createTransition<InRangeTransition>();

	_ai->add(find, gainSightTransition, towardsPlayer);
	_ai->add(towardsPlayer, lostSightTransition, find);

	_ai->add(towardsPlayer, inRangeTransition, attackPlayer);
	_ai->add(attackPlayer, lostSightTransition, find);

	_ai->setInitialState(find);
}

template<typename T>
State* InvisibleEnemyAIComponent::createState()
{
	T* state = new T();
	_states.push_back(state);
	return state;
}

template<typename T>
Transition* InvisibleEnemyAIComponent::createTransition()
{
	T* transition = new T();
	_transitions.push_back(transition);
	return transition;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
//-------------  STATES    STATES    STATES    STATES    STATES    STATES    STATES    STATES    STATES    STATES    STATES    STATES  -------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------

void InvisibleEnemyAIComponent::FindState::execute(Component* component)
{
	CAST_COMPONENT;
}

void InvisibleEnemyAIComponent::GoTowardsPlayerState::execute(Component* component)
{
	CAST_COMPONENT;
}

void InvisibleEnemyAIComponent::AttackPlayerState::execute(Component* component)
{
	CAST_COMPONENT;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
//-------------  TRANSITIONS   TRANSITIONS  TRANSITIONS  TRANSITIONS  TRANSITIONS  TRANSITIONS  TRANSITIONS  TRANSITIONS  TRANSITIONS  -------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------

bool InvisibleEnemyAIComponent::LostSightTransition::evaluate(Component* component)
{
	CAST_COMPONENT;
	return false;
}

bool InvisibleEnemyAIComponent::GainSightTransition::evaluate(Component* component)
{
	CAST_COMPONENT;
	return false;
}

bool InvisibleEnemyAIComponent::InRangeTransition::evaluate(Component* component)
{
	CAST_COMPONENT;
	return false;
}
