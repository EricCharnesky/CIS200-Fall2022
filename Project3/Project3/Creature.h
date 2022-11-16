#pragma once

class Creature {
private:
	int strength;
	int defense;
	Creature* nextCreature;

public:

	Creature(int strength, int defense, Creature* nextCreature = nullptr) {
		this->strength = strength;
		this->defense = defense;
		this->nextCreature = nullptr;
		
		setNextCreature(nextCreature);
		
	}

	// todo later - might be easier
	/*Creature& addCreature(Creature* creature) {

		Creature* current = creature;

		while (current != nullptr) {
			if (this->getDefense() < creature->getDefense()) {

			}

			current = current->getNextCreature();
		}

		
	}*/

	Creature(const Creature& other) {
		this->strength = other.strength;
		this->defense = other.defense;
		setNextCreature(other.nextCreature);
	}

	Creature& operator=(const Creature& other) {

		if (this != &other) {
			delete this->nextCreature;

			this->strength = other.strength;
			this->defense = other.defense;
			setNextCreature(other.nextCreature);
		}

		return *this;
	}

	~Creature() {
		Creature* nextCreatureToDelete = this->nextCreature;

		while (nextCreatureToDelete != nullptr) {
			Creature* temp = nextCreatureToDelete->nextCreature;
			delete nextCreatureToDelete;
			nextCreatureToDelete = temp;
		}
	}

	 int getStrength() {
		 return this->strength;
	}

	 int getDefense() {
		 return this->defense;
	 }

	 Creature* getNextCreature() {
		 return this->nextCreature;
	 }

	 void setNextCreature(Creature* nextCreature) {

		 Creature* thisLastCreature = this;
		 Creature* toCopyNextCreature = nextCreature->nextCreature;

		 while (toCopyNextCreature != nullptr) {
			 thisLastCreature->nextCreature = new Creature(toCopyNextCreature->strength, toCopyNextCreature->defense);
			 thisLastCreature = thisLastCreature->nextCreature;
			 toCopyNextCreature = toCopyNextCreature->nextCreature;
		 }
	 }

};
	