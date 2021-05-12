#pragma once

#ifndef PLAYERKEYSCOMPONENT_H
#define PLAYERKEYSCOMPONENT_H

#include "Component.h"

class GameObject;

class PlayerKeysComponent : public Component
{
public:

	PlayerKeysComponent();
	~PlayerKeysComponent();

	/// <summary>
	/// Adds one key
	/// </summary>
	void addKey();

	/// <summary>
	/// Spends one key
	/// </summary>
	void spendKey();

	/// <summary>
	/// Returns the number of keys
	/// </summary>
	/// <returns></returns>
	inline const int getKeys() const { return _nKeys; }

private:

	int _nKeys;
};

#endif // !PLAYERKEYSCOMPONENT_H