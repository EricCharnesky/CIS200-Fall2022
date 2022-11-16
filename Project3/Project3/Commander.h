#pragma once

#include "Creature.h"
#include <string>

using namespace std;

class Commander {
private:
	int hitPoints;
	Creature* first;

	void sortCreatures() {

		Creature* newFirstCreature = nullptr;

		while (this->first != nullptr) {

			Creature* currentCreature = this->first;

			Creature* creatureWithHighestDefense = new Creature(0, 0);

			while (currentCreature != nullptr) {

				if (currentCreature->getDefense() > creatureWithHighestDefense->getDefense()) {
					creatureWithHighestDefense = currentCreature;
				}
				else if (currentCreature->getDefense() == creatureWithHighestDefense->getDefense()) {
					if (currentCreature->getStrength() > creatureWithHighestDefense->getStrength()) {
						creatureWithHighestDefense = currentCreature;
					}
				}

				currentCreature = currentCreature->getNextCreature();
			}
			if (newFirstCreature == nullptr) {
				newFirstCreature = creatureWithHighestDefense;
				newFirstCreature->setNextCreature(nullptr);
			}
			else {
				Creature* currentNew = newFirstCreature;
				while (currentNew->getNextCreature() != nullptr) {
					currentNew = currentNew->getNextCreature();
				}
				currentNew->setNextCreature(creatureWithHighestDefense);
				currentNew->getNextCreature()->setNextCreature(nullptr);
			}

			if (creatureWithHighestDefense == this->first) {
				this->first = this->first->getNextCreature();
			}
			else {
				Creature* current = this->first;
				while (current->getNextCreature() != creatureWithHighestDefense) {
					current = current->getNextCreature();
				}
				current->getNextCreature()->setNextCreature(current->getNextCreature()->getNextCreature());
			}
		}

		this->first = newFirstCreature;
	}

public:
	Commander() {
		hitPoints = 40;
		first = nullptr;
	}

	void addCreature(Creature* creature) {
		if (first == nullptr) {
			first = creature;
		}
		else {
			Creature* current = first;
			while (current->getNextCreature() != nullptr) {
				current = current->getNextCreature();
			}
			current->setNextCreature(creature);
		}
		
		sortCreatures();
	}

	void removeFirstCreature() {
		this->first = this->first->getNextCreature();
	}

	int getHitPoints() {
		return this->hitPoints;
	}

	void damage(int damage) {
		this->hitPoints -= damage;
	}

	void Battle(Commander& other) {
		while (this->first != nullptr && other.first != nullptr) {
			Creature* myFirst = this->first;
			Creature* otherFirst = other.first;

			if (myFirst->getStrength() >= otherFirst->getDefense()) {
				other.removeFirstCreature();
			}
			if (otherFirst->getStrength() >= myFirst->getDefense()) {
				this->removeFirstCreature();
			}

			if (myFirst->getStrength() < otherFirst->getDefense() &&
				otherFirst->getStrength() < myFirst->getDefense()) {
				// neither creature died, combat stops
				break;
			}
		}

		// I still have creatures left to attack but you don't
		if (other.first == nullptr) {
			Creature* current = this->first;

			while (current != nullptr) {
				other.damage(current->getStrength());
				current = current->getNextCreature();
			}
		}

		// You still have creatures left to attack but I don't
		if (this->first == nullptr) {
			Creature* current = other.first;

			while (current != nullptr) {
				this->damage(current->getStrength());
				current = current->getNextCreature();
			}
		}
	}

	string getCreatureString() {
		string creatures = "";

		Creature* current = this->first;
		int creatureCount = 0;

		while (current != nullptr) {
			creatureCount++;
			creatures += "Creature Number: " + to_string(creatureCount)
				+ "Strength: " + to_string(current->getStrength())
				+ "Defense: " + to_string(current->getDefense())
				+ "\n";
		}
	}

};
