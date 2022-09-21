#pragma once

using namespace std;

#include <string>
#include <stdexcept>

class Item {

private:
	string name;
	double price;
	int quantity;

public:
	Item(string name, double price, int quantity = 1) {
		this->name = name;
		setPrice(price);
		setQuantity(quantity);
	}

	string getName() {
		return this->name;
	}

	double getPrice() {
		return this->price;
	}

	int getQuantity() {
		return this->quantity;
	}

	void setPrice(double price) {
		if (price <= 0) {
			throw logic_error("price can't be <= 0");
		}
		this->price = price;
	}

	void setQuantity(int quantity) {
		if (quantity <= 0) {
			throw logic_error("quantity can't be <= 0");
		}
		this->quantity = quantity;
	}

	virtual double getTotalPrice() {
		return this->price * this->quantity;
	}

};