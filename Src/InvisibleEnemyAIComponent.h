#pragma once
#ifndef _INVISIBLE_AI_COMPONENT_
#define _INVISIBLE_AI_COMPONENT_

#include "Component.h"
#include "FSM/FSM.h"

class InvisibleAIComponent : public Component {
public:
	InvisibleAIComponent();

	~InvisibleAIComponent();

	void awake(luabridge::LuaRef& data) override;

	void update() override;

private:

	template <typename T>
	State* createState();

	template <typename T>
	Transition* createTransition();

	FSM* _ai;

	std::list<State*> _states;
	std::list<Transition*> _transitions;

	//States
	class FindState : public State { public: void execute(Component* component); };
	class GoTowardsPlayerState : public State { public: void execute(Component* component); };
	class AttackPlayerState : public State { public: void execute(Component* component); };

	//Transitions
	class LostSightTransition : public Transition { public: bool evaluate(Component* component); };
	class GainSightTransition : public Transition { public: bool evaluate(Component* component); };
	class InRangeTransition : public Transition { public: bool evaluate(Component* component); };
};

#endif // !_INVISIBLE_AI_COMPONENT_
