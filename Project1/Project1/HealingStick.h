#pragma once

#include "Weapon.h"

class HealingStick : public Weapon {

public:
	HealingStick(string name, int maxDamage, double range) : Weapon(name, maxDamage, range) {
		// empty
	}

	int getDamage() {
		return Weapon::getDamage() * -1;
	}
};