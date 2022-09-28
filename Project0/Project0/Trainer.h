#pragma once

using namespace std;

#include <string>
#include "FightingPet.h"
#include <stdexcept>

class Trainer {
private:
	string name;
	int level;
	int experiencePoints;
	int maxNumberOfFightingPets;
	int currentNumberOfFightingPets;
	FightingPet* pets;

public:
	Trainer(string name, int maxNumberOfFightingPets = 50) {
		this->name = name;
		this->level = 1;
		this->experiencePoints = 0;
		this->maxNumberOfFightingPets = maxNumberOfFightingPets;
		this->currentNumberOfFightingPets = 0;
		pets = new FightingPet[maxNumberOfFightingPets];
	}

	~Trainer() {
		delete[] pets;
	}

	Trainer(const Trainer& trainer) {
		this->name = trainer.name;
		this->level = trainer.level;
		this->experiencePoints = trainer.experiencePoints;
		this->maxNumberOfFightingPets = trainer.maxNumberOfFightingPets;
		this->currentNumberOfFightingPets = trainer.currentNumberOfFightingPets;
		this->pets = new FightingPet[this->maxNumberOfFightingPets];
		for (int index = 0; index < this->currentNumberOfFightingPets; index++) {
			this->pets[index] = trainer.pets[index];
		}
	}

	Trainer& operator=(const Trainer& trainer) {
		if (this != &trainer) {
			delete[] pets;
			this->name = trainer.name;
			this->level = trainer.level;
			this->experiencePoints = trainer.experiencePoints;
			this->maxNumberOfFightingPets = trainer.maxNumberOfFightingPets;
			this->currentNumberOfFightingPets = trainer.currentNumberOfFightingPets;
			this->pets = new FightingPet[this->maxNumberOfFightingPets];
			for (int index = 0; index < this->currentNumberOfFightingPets; index++) {
				this->pets[index] = trainer.pets[index];
			}
		}
		return *this;
	}

	string getName() {
		return this->name;
	}

	void setName(string name) {
		this->name = name;
	}

	int getLevel() {
		return this->level;
	}

	int getExperiencePoints() {
		return this->experiencePoints;
	}

	int getMaxNumberOfFightingPets() {
		return this->maxNumberOfFightingPets;
	}

	int getCurrentNumberOfFightingPets() {
		return this->currentNumberOfFightingPets;
	}

	FightingPet getFightingPet(int index) {
		return pets[index];
	}

	void addExperiencePoints(int experiencePoints) {
		this->experiencePoints += experiencePoints;
		if (this->experiencePoints > this->level * 1000) {
			this->level++;
			this->experiencePoints = 0;
		}
	}

	void addFightingPet(FightingPet pet) {
		if (this->currentNumberOfFightingPets == this->maxNumberOfFightingPets) {
			throw logic_error("You are out of space for fighting pets!");
		}
		pets[this->currentNumberOfFightingPets] = pet;
		this->currentNumberOfFightingPets++;
	}

	void addMoreFightingPetStorage(int numberOfSlotsToAdd = 50) {
		this->maxNumberOfFightingPets += numberOfSlotsToAdd;

		FightingPet* newPets =
			new FightingPet[this->maxNumberOfFightingPets];

		for (int index = 0; index < this->currentNumberOfFightingPets; index++) {
			newPets[index] = this->pets[index];
		}

		delete[] this->pets;

		this->pets = newPets;
	}
};