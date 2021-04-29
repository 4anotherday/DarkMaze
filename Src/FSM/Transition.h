#pragma once
#ifndef _TRANSITION_
#define _TRANSITION_

class Component;

class Transition {
public:
	virtual ~Transition() {}
	virtual bool evaluate(Component* component) = 0;
};

#endif // !_TRANSITION_
