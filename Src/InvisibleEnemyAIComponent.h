#pragma once
#ifndef _INVISIBLE_AI_COMPONENT_
#define _INVISIBLE_AI_COMPONENT_

#include "Component.h"
#include "FSM/FSM.h"
#include "Vector3.h"
#include <algorithm>
class Transform;


class InvisibleEnemyAIComponent : public Component {
public:
	InvisibleEnemyAIComponent();

	~InvisibleEnemyAIComponent();

	void awake(luabridge::LuaRef& data) override;

	void update() override;

	inline Transform* getMyTransform() const { return _myTransform; }
	inline Transform* getPlayerTransform() const { return _transformPlayer; }

	inline void updateRadiusFind(double delta) { _radiusFindPlayer = std::min(_maxRadiusFindPlayer, std::max(_minRadiusFindPlayer, (_radiusFindPlayer + delta))); }

	inline void setRadius(double radius) { _radiusFindPlayer = std::min(_maxRadiusFindPlayer, std::max(_minRadiusFindPlayer, radius));}

private:

	void createFSM(luabridge::LuaRef& data);

	template <typename T>
	T* createState();

	template <typename T>
	T* createTransition();

	Transform* _transformPlayer;
	Transform* _myTransform;

	FSM* _ai;

	std::list<State*> _states;
	std::list<Transition*> _transitions;

	double _radiusFindPlayer, _maxRadiusFindPlayer, _minRadiusFindPlayer;

	//States
	class FindState : public State { 
	public:	
		void execute(Component* component); 
		inline void setRadius(double* radius) { _radiusFromPlayer = radius; }
	private:
		void findNewTargetPos(const Vector3& playerPos);
		void moveToTargetPos();

		double* _radiusFromPlayer;
		Vector3 _targetPos;
	};

	class GoTowardsPlayerState : public State { 
	public:

		void execute(Component* component);
	private:

	};

	class AttackPlayerState : public State { 
	public:

		void execute(Component* component); 
	private:

	};

	class TowardsSoundState : public State {
	public:

		void execute(Component* component);
	private:

	};


	//Transitions
	class LostSightTransition : public Transition {
	public:

		bool evaluate(Component* component); 
	private:
	};

	class GainSightTransition : public Transition { 
	public:

		bool evaluate(Component* component);
	private:

	};

	class LoudSoundTransition : public Transition {
	public:

		bool evaluate(Component* component);
	private:

	};

	class NoSoundTransition : public Transition {
	public:

		bool evaluate(Component* component);
	private:

	};

	class InRangeTransition : public Transition { 
	public:

		bool evaluate(Component* component); 
	private:

	};
};

#endif // !_INVISIBLE_AI_COMPONENT_
