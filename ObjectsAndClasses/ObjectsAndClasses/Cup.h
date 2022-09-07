#pragma once

using namespace std;

#include <string>

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

	bool drink(int millilitersToDrink) {
		if (millilitersToDrink < 0) {
			return false;
		}

		this->currentVolumeOfContentsInMilliliters -= millilitersToDrink;

		if (this->currentVolumeOfContentsInMilliliters < 0) {
			this->currentVolumeOfContentsInMilliliters = 0;
			return false;
		}
		return true;
	}

	bool fillCup(int millilitersToAdd) {
		if (millilitersToAdd < 0) {
			return false;
		}

		this->currentVolumeOfContentsInMilliliters += millilitersToAdd;
		if (this->currentVolumeOfContentsInMilliliters >
			this->maxVolumeInMilliliters) {
			this->currentVolumeOfContentsInMilliliters =
				this->maxVolumeInMilliliters;
			return false;
		}
		return true;
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