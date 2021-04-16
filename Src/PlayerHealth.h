#pragma once

class Component;
class GameObject;

class HealthComponent : public Component
{
public:
	/// <summary>
	/// initialize the player with "lives" lives
	/// </summary>
	/// <param name="nLives">initial lives of the player</param>
	HealthComponent(unsigned int healthPoints);

	/// <summary>
	/// initialize the player with "lives" lives
	/// </summary>
	/// <param name="nLives">initial lives of the player</param>
	/// <param name="go">the gameObject this component will be attached to</param>
	HealthComponent(unsigned int healthPoints, GameObject* go);

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
private:

	/// <summary>
	/// Called when health points reach zero or less
	/// </summary>
	void onDead();

	int _healthPoints;
	int _maxHealthPoints;
};

