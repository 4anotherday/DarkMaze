#pragma once

#ifndef HEALTHCOMPONENT_H
#define HEALTHCOMPONENT_H

#include "Component.h"
class GameObject;
class AudioSourceComponent;
class HealthComponent : public Component
{
public:

	HealthComponent();


	/// <summary>
	/// initializes the HP of the player
	/// </summary>
	/// <param name="data"></param>
	void awake(luabridge::LuaRef& data);

	virtual void start() override;

	/// <summary>
	/// add n life points to the player
	/// </summary>
	/// <param name="n">number of life points to add</param>
	void addHPs(unsigned int n);

	/// <summary>
	/// lose one life
	/// </summary>
	void loseHPs();

	/// <summary>
	/// Lose an amount of health points
	/// </summary>
	/// <param name="n">Amount of health points to lose</param>
	void loseHPs(unsigned int n);

	/// <summary>
	/// reset the player life points
	/// </summary>
	void reset();

	/// <summary>
	/// gets the player's current HP
	/// </summary>
	/// <returns>the player's current health points</returns>
	int getCurrentHP() { return _healthPoints; }
private:

	/// <summary>
	/// Called when health points reach zero or less
	/// </summary>
	void onDead();

	AudioSourceComponent* _audioSource;
	int _healthPoints;
	int _maxHealthPoints;
};

#endif // !HEALTHCOMPONENT_H