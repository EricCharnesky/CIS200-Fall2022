#pragma once

using namespace std;

#include <string>

class Weapon {
private:
	string name;
	double range;
	int maxDamage;

public:

	Weapon(string name, int maxDamage, double range) {
		this->name = name;
		this->maxDamage = maxDamage;
		this->range = range;
	}

	string getName() {
		return name;
	}

	virtual int getDamage() {
		return rand() % maxDamage + 1;
	}
	double getRange() {
		return range;
	}
};