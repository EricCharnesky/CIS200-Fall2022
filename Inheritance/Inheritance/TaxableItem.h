#pragma once

#include "Item.h"

class TaxableItem : public Item {
private:
	double taxRate;

public:
	TaxableItem(string name, double price,
		double taxRate, int quantity = 1) 
		: Item(name, price, quantity) {
		setTaxRate(taxRate);
	}

	void setTaxRate(double taxRate) {
		if (taxRate <= 0) {
			throw logic_error("Tax rate can't be <= 0");
		}
		if (taxRate < 1) {
			this->taxRate = taxRate;
		}
		else {
			this->taxRate = taxRate/100;
		}
	}

	double getTaxRate() {
		return this->taxRate;
	}

	double getTotalPrice() {
		return Item::getTotalPrice() * (1 + this->taxRate);
	}
};