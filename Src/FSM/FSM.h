#pragma once
#ifndef _FSM_
#define _FSM_

#include "State.h"
#include "Transition.h"
#include <map>
#include <list>

class FSM {
public:

	/// <summary>
	/// </summary>
	/// <param name="component">: component to be called to get usefull data</param>
	FSM(Component* component);

	/// <summary>
	/// (Source -> Target) if transitions returns true
	/// </summary>
	void add(State* source, Transition* transition, State* target);

	/// <summary>
	/// Starting state
	/// </summary>
	/// <param name="initial"></param>
	void setInitialState(State* initial);

	/// <summary>
	/// Executes one step
	/// </summary>
	void step();

	/// <summary>
	/// Sets the currentState to be initialState
	/// </summary>
	void reset();

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
