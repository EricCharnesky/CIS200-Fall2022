#pragma once

using namespace std;

#include <string>
#include "Weapon.h"

class Character {
private:
	string name;
	int maxHitPoints;
	int currentHitPoints;
	int xLocation;
	int yLocation;
	int dexterity;
	Weapon* weapon;


protected:
	bool isWithinRange(Character target, double range) {
		double distanceToTarget = sqrt(
			(pow(xLocation - target.getXLocation(), 2) +
			(pow(yLocation - target.getYLocation(), 2))));
		return range >= distanceToTarget;
	}

	bool rollToHit(Character target) {
		int d20Roll = rand() % 20 + 1;
		return d20Roll > target.getDexterity();
	}

public:
	Character(string name, int maxHitPoints, int xLocation, 
		int yLocation, int dexterity, Weapon* weapon = nullptr) {
		this->name = name;
		this->maxHitPoints = maxHitPoints;
		this->currentHitPoints = maxHitPoints;
		this->dexterity = dexterity;
		setXLocation(xLocation);
		setYLocation(yLocation);
		setWeapon(weapon);
	}

	virtual string attack(Character& target) {
		if (currentHitPoints != 0) {
			if (weapon == nullptr && isWithinRange(target, sqrt(2)) && rollToHit(target)) {
				target.takeDamage(1);
				return "You hit the target and they took 1 damage";
			}
			else if (weapon != nullptr && isWithinRange(target, weapon->getRange()) && rollToHit(target)) {
				int damage = weapon->getDamage();
				target.takeDamage(damage);
				return "You hit the target and they took " + to_string(damage) + " damage";
			}
			else {
				return "You missed!";
			}
		}
		else {
			return "You can't attack when you have 0 hit points";
		}

	}

	void takeDamage(int damage) {
		currentHitPoints -= damage;
		if (currentHitPoints < 0) {
			currentHitPoints = 0;
		}
		if (currentHitPoints > maxHitPoints) {
			currentHitPoints = maxHitPoints;
		}
	}

	string getName() {
		return name;
	}

	int getMaxHitPoint() {
		return maxHitPoints;
	}
	int getCurrentHitPoints() {
		return currentHitPoints;
	}
	int getXLocation() {
		return xLocation;
	}
	int getYLocation() {
		return yLocation;
	}

	int getDexterity() {
		return dexterity;
	}

	Weapon* getWeapon() {
		return weapon;
	}

	void setWeapon(Weapon* weapon) {
		this->weapon = weapon;
	}

	void setXLocation(int xLocation) {
		this->xLocation = xLocation;
	}

	void setYLocation(int yLocation) {
		this->yLocation = yLocation;
	}

};