#pragma once

#include "Character.h"

class MagicCharcter : public Character {
private:
	int intelligence;
public:
	MagicCharcter(string name, int maxHitPoints, int xLocation,
		int yLocation, int dexterity, int intelligence) : Character(name, maxHitPoints, xLocation, yLocation, dexterity) {
		this->intelligence = intelligence;
	}

	string attack(Character& target) {
		if (isWithinRange(target, 10) && rollToHit(target)) {
			target.takeDamage(intelligence / 3);
			return "You hit the target and it took " + to_string((intelligence / 3)) + " damage";
		}
		else {
			return "You missed!";
		}
	}

};