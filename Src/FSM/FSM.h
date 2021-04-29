#pragma once
#ifndef _FSM_
#define _FSM_

#include "State.h"
#include "Transition.h"
#include <map>
#include <list>

class FSM {
public:

	FSM(Component* component);

	~FSM();

	void add(State* source, Transition* transition, State* target);

	void setInitialState(State* initial);

	void run();

private:

	struct TransitionState {
		Transition* transition;
		State* target;
	};

	Component* _component;
	State* _current;
	State* _initial;
	std::map<State*, std::list<TransitionState>> _machine;
};

#endif // !_FSM_
