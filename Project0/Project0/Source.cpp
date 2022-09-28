using namespace std;

#include <iostream>
#include <string>
#include "Trainer.h"
#include "Source.h"

void printPets(Trainer& trainer)
{
	cout << "Listing all pets for " << trainer.getName() << endl;
	for (int index = 0; index < trainer.getCurrentNumberOfFightingPets(); index++) {
		FightingPet pet = trainer.getFightingPet(index);
		cout << "Name: " << pet.getName()
			<< " - Number: " << pet.getNumber()
			<< " - Combat Power: " << pet.getCombatPower()
			<< endl;
	}
}

int main() {
	Trainer eric("Eric");
	FightingPet pica("Pica", 1);
	eric.addFightingPet(pica);

	FightingPet charman("Charman", 2);
	eric.addFightingPet(charman);

	printPets(eric);

	Trainer jeb(eric);

	jeb.setName("Jeb");

	printPets(jeb);

	Trainer* vivi = new Trainer("Vivi");


	printPets(*vivi);

	for (int addition = 0; addition < 10; addition++) {
		vivi->addMoreFightingPetStorage(10000);
	}



	cout << "Memory?" << endl;

	delete vivi;

	cout << "Memory?" << endl;
}