#include "FSM.h"

FSM::FSM(Component* component): _component(component), _current(nullptr), _initial(nullptr), _machine()
{
}

FSM::~FSM()
{
}

void FSM::add(State* source, Transition* transition, State* target)
{
	auto it = _machine.find(source);
	if (it == _machine.end()) {
		_machine.insert(std::make_pair(source, std::list<TransitionState>({ {transition, target} })));
	}
	else {
		it->second.push_back({ transition, target });
	}
}

void FSM::setInitialState(State* initial)
{
	_initial = initial;
}

void FSM::run()
{
	auto it = _machine.find(_current);
	//If there are no transitions to be made
	if (it == _machine.end()) {
		_current->execute(_component);
		return;
	}
	//Look for any translation to be true
	for (TransitionState& ts : it->second) {
		if (ts.transition->evaluate(_component)) {
			_current = ts.target;
			break;
		}
	}

	_current->execute(_component);
}
