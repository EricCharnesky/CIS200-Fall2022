#pragma once
// from https://github.com/EricCharnesky/CIS200-Fall2022/blob/main/ObjectsAndClasses/ObjectsAndClasses/Cup.h


using namespace std;

#include <string>
#include <stdexcept>

class Cup {
private:
	string color;
	int maxVolumeInMilliliters;
	int currentVolumeOfContentsInMilliliters;
	bool hasLid;
	bool hasHandle;
	string contents;
	string typeOfMaterialMadeFrom;
public:

	Cup(string color, int maxVolumeInMilliliters, bool hasLid,
		bool hasHandle, string typeOfMaterialMadeFrom,
		int currentVolumeOfContentsInMilliliters = 0, string contents = "") {
		this->color = color;
		this->maxVolumeInMilliliters = maxVolumeInMilliliters;
		this->hasLid = hasLid;
		this->hasHandle = hasHandle;
		this->typeOfMaterialMadeFrom = typeOfMaterialMadeFrom;
		this->currentVolumeOfContentsInMilliliters = currentVolumeOfContentsInMilliliters;
		this->contents = contents;
	}

	void drink(int millilitersToDrink) {
		if (millilitersToDrink < 0) {
			throw logic_error("You can't drink negative milliliters");
		}

		this->currentVolumeOfContentsInMilliliters -= millilitersToDrink;

		if (this->currentVolumeOfContentsInMilliliters < 0) {
			this->currentVolumeOfContentsInMilliliters = 0;
			throw logic_error("You can't drink more than what's in the cup");
		}
		
	}

	void fillCup(int millilitersToAdd) {
		if (millilitersToAdd < 0) {
			throw logic_error("You can't add a negative amount");
		}

		this->currentVolumeOfContentsInMilliliters += millilitersToAdd;
		if (this->currentVolumeOfContentsInMilliliters >
			this->maxVolumeInMilliliters) {
			this->currentVolumeOfContentsInMilliliters =
				this->maxVolumeInMilliliters;
			throw logic_error("You put more in than fit and spilled everywhere");
		}

	}

	void setContents(string contents) {
		this->contents = contents;
	}

	string getColor() {
		return this->color;
	}

	int getMaxVolumeInMilliliters() {
		return this->maxVolumeInMilliliters;
	}

	int getCurrentVolumeOfContentsInMilliliters() {
		return this->currentVolumeOfContentsInMilliliters;
	}

	bool getHasLid() {
		return this->hasLid;
	}

	bool getHasHandle() {
		return this->hasHandle;
	}

	string getContents() {
		return this->contents;
	}

	string getTypeOfMaterialMadeFrom() {
		return this->typeOfMaterialMadeFrom;
	}
};