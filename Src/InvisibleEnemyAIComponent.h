#pragma once
#ifndef _INVISIBLE_AI_COMPONENT_
#define _INVISIBLE_AI_COMPONENT_

#include "Component.h"
#include "FSM/FSM.h"
#include "Vector3.h"
#include <algorithm>

class Transform;
class RigidBodyComponent;

class InvisibleEnemyAIComponent : public Component {
public:
	InvisibleEnemyAIComponent();

	~InvisibleEnemyAIComponent();

	void awake(luabridge::LuaRef& data) override;

	void start() override;

	void update() override;

	void moveTowardsPos(const Vector3& pos);

	/// <summary>
	/// Called from outside when a sound is created
	/// </summary>
	/// <param name="soundLocation">: global position</param>
	/// <param name="intensity">: 0 to 1, 0 representing no sound and 1 very high volume</param>
	void sound(const Vector3& soundLocation, float intensity);

	inline Transform* getMyTransform() const { return _myTransform; }
	inline Transform* getPlayerTransform() const { return _transformPlayer; }

	inline void updateRadiusFind(double delta) { _radiusFindPlayer = std::min(_maxRadiusFindPlayer, std::max(_minRadiusFindPlayer, (_radiusFindPlayer + delta))); }
	inline void setFindRadius(double radius) { _radiusFindPlayer = std::min(_maxRadiusFindPlayer, std::max(_minRadiusFindPlayer, radius)); }

	void justLostSight();
	inline const Vector3& getLastKnownPosition() const { return _lastKnownPosition; }

private:

	void createFSM();

	template <typename T>
	T* createState();

	template <typename T>
	T* createTransition();

	Transform* _transformPlayer;
	Transform* _myTransform;

	RigidBodyComponent* _rb;
	double _speed;

	FSM* _ai;

	std::list<State*> _states;
	std::list<Transition*> _transitions;

	//--------------------------------------------------------------------------------
	//----  AI-RELATED VARIABLES    AI-RELATED VARIABLES    AI-RELATED VARIABLES  ----
	//--------------------------------------------------------------------------------

	//Find-related
	double _radiusFindPlayer, _maxRadiusFindPlayer, _minRadiusFindPlayer;

	//Sighting-related
	double _sightingDistance;
	Vector3 _lastKnownPosition;
	float _justLostSightTime;
	float _lostSightSearchTime;

	//Attack-related
	float _attackRange;

	//Sound-related
	double _hearingDistance;
	Vector3 _soundLocation;
	float _soundTime;
	float _soundTimeSearchTime;

	//--------------------------------------------------------------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------------------------------------------------------
	//-------------  STATES    STATES    STATES    STATES    STATES    STATES    STATES    STATES    STATES    STATES    STATES    STATES  -------------
	//--------------------------------------------------------------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------------------------------------------------------

	class FindState : public State { 
	public:	
		void execute(Component* component); 
		inline void setFindRadius(double* radius) { _radiusFromPlayer = radius; }
		inline void setJustLostTime(float* time) { _justLostTime = time; }
	private:
		double* _radiusFromPlayer = nullptr;
		float* _justLostTime = nullptr;
		Vector3 _targetPos = Vector3();
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
		inline void setSoundPos(Vector3* pos) { _soundPos = pos; }
	private:
		Vector3* _soundPos;
	};

	//--------------------------------------------------------------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------------------------------------------------------
	//-------------  TRANSITIONS   TRANSITIONS  TRANSITIONS  TRANSITIONS  TRANSITIONS  TRANSITIONS  TRANSITIONS  TRANSITIONS  TRANSITIONS  -------------
	//--------------------------------------------------------------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------------------------------------------------------

	class LostSightTransition : public Transition {
	public:
		bool evaluate(Component* component); 
		inline void setSightingDistance(double* distance) { _sightingDistance = distance; }
	private:
		double* _sightingDistance = nullptr;
	};

	class GainSightTransition : public Transition { 
	public:
		bool evaluate(Component* component);
		inline void setSightingDistance(double* distance) { _sightingDistance = distance; }
	private:
		double* _sightingDistance = nullptr;
	};

	class LoudSoundTransition : public Transition {
	public:
		bool evaluate(Component* component);
		inline void setSoundTime(float* time) { _soundTime = time; }
	private:
		float* _soundTime;
	};

	class NoSoundTransition : public Transition {
	public:
		bool evaluate(Component* component);
		inline void setSoundTime(float* time) { _soundTime = time; }
	private:
		float* _soundTime;
	};

	class InRangeTransition : public Transition { 
	public:
		bool evaluate(Component* component); 
		inline void setRange(float range) { _attackRange = range; }
	private:
		float _attackRange = 2;
	};
};

#endif // !_INVISIBLE_AI_COMPONENT_
