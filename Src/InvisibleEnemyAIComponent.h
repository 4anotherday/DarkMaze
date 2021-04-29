#pragma once
#ifndef _INVISIBLE_AI_COMPONENT_
#define _INVISIBLE_AI_COMPONENT_

#include "Component.h"
#include "FSM/FSM.h"

class Transform;

class InvisibleEnemyAIComponent : public Component {
public:
	InvisibleEnemyAIComponent();

	~InvisibleEnemyAIComponent();

	void awake(luabridge::LuaRef& data) override;

	void update() override;

private:

	void createFSM(luabridge::LuaRef& data);

	template <typename T>
	State* createState();

	template <typename T>
	Transition* createTransition();

	Transform* _transformPlayer;

	FSM* _ai;

	std::list<State*> _states;
	std::list<Transition*> _transitions;

	//States
	class FindState : public State { 
		void execute(Component* component); 
	};
	class GoTowardsPlayerState : public State { 
		void execute(Component* component);
	};
	class AttackPlayerState : public State { 
		void execute(Component* component); 
	};

	//Transitions
	class LostSightTransition : public Transition { 
		bool evaluate(Component* component); 
	};
	class GainSightTransition : public Transition { 
		bool evaluate(Component* component);
	};
	class InRangeTransition : public Transition { 
		bool evaluate(Component* component); 
	};
};

#endif // !_INVISIBLE_AI_COMPONENT_
