#pragma once

using namespace std;

#include <string>
#include <iostream>

class Item {
private:
	string name;
	double price;
public:
	Item() {
		name = "";
		price = 0;
	}

	Item(string name, double price) {
		this->name = name;
		this->price = price;
	}

	string getName() {
		return name;
	}

	double getPrice() {
		return price;
	}

	void setName(string name) {
		this->name = name;
	}

	void setPrice(double price) {
		this->price = price;
	}

	bool operator< (const Item& other) const {
		return price < other.price;
	}

	friend ostream& operator<< (ostream& os, const Item& item){
		return os << "Name: " << item.name << " Price: $" << item.price;
	}

};