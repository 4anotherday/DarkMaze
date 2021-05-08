#pragma once
#ifndef _STATE_
#define _STATE_

class Component;

class State {
public:
	virtual ~State() {}
	virtual void execute(Component* component) = 0;

	const char* name;
};

#endif // !_STATE_
