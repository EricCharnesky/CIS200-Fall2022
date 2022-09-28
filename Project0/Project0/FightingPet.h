#pragma once

using namespace std;

#include <string>

class FightingPet {
private:
	string name;
	int number;
	int combatPower;

public:
	FightingPet(string name = "", int number = 0, int combatPower = 1) {
		this->name = name;
		this->number = number;
		this->combatPower = combatPower;
	}

	string getName() {
		return this->name;
	}

	int getNumber() {
		return this->number;
	}

	int getCombatPower() {
		return this->combatPower;
	}

	void setCombatPower(int combatPower) {
		this->combatPower = combatPower;
	}

};