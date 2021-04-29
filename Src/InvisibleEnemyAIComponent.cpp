#include "InvisibleEnemyAIComponent.h"
#include "UserComponentsIDs.h"

ADD_COMPONENT(InvisibleAIComponent)

InvisibleAIComponent::InvisibleAIComponent() : Component(UserComponentId::InvisibleEnemyAIComponent),
	_ai(nullptr), _states(), _transitions()
{

}

InvisibleAIComponent::~InvisibleAIComponent()
{
	delete _ai; _ai = nullptr;
	for (State* s : _states) {
		delete s; s = nullptr;
	}
	for (Transition* t : _transitions) {
		delete t; t = nullptr;
	}
}

void InvisibleAIComponent::awake(luabridge::LuaRef& data)
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
	_ai->add(find, inRangeTransition, attackPlayer);
	_ai->add(towardsPlayer, inRangeTransition, attackPlayer);
	_ai->add(attackPlayer, lostSightTransition, find);
}

void InvisibleAIComponent::update()
{
	_ai->run();
}

template<typename T>
State* InvisibleAIComponent::createState()
{
	T* state = new T();
	_states.push_back(state);
	return state;
}

template<typename T>
Transition* InvisibleAIComponent::createTransition()
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

void InvisibleAIComponent::FindState::execute(Component* component)
{

}

void InvisibleAIComponent::GoTowardsPlayerState::execute(Component* component)
{

}

void InvisibleAIComponent::AttackPlayerState::execute(Component* component)
{

}

//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
//-------------  TRANSITIONS   TRANSITIONS  TRANSITIONS  TRANSITIONS  TRANSITIONS  TRANSITIONS  TRANSITIONS  TRANSITIONS  TRANSITIONS  -------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------

bool InvisibleAIComponent::LostSightTransition::evaluate(Component* component)
{
	return false;
}

bool InvisibleAIComponent::GainSightTransition::evaluate(Component* component)
{
	return false;
}

bool InvisibleAIComponent::InRangeTransition::evaluate(Component* component)
{
	return false;
}
