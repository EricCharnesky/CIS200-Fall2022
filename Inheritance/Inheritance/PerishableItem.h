#pragma once

#include "Item.h"

class PerishableItem : public Item {
private:
	int daysUntilExpiration;

public:
	PerishableItem(string name, double price,
		int daysUntilExpiration, int quantity = 1)
		: Item(name, price, quantity) {
		this->daysUntilExpiration = daysUntilExpiration;
	}

	int getDaysUntilExpiration() {
		return this->daysUntilExpiration;
	}

	void nextDay() {
		this->daysUntilExpiration--;
	}

	double getTotalPrice() {
		double totalPrice = Item::getTotalPrice();
		if (daysUntilExpiration == 2) {
			return totalPrice * .75;
		}
		else if (daysUntilExpiration == 1) {
			return totalPrice * .5;
		}
		else if (daysUntilExpiration <= 0) {
			return 0;
		}
		return totalPrice;
	}

};