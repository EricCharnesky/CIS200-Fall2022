#pragma once

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Item {
private:

public:
	int quantity;
	double price;
	string name;

	Item(string name, int quantity, double price) {
		this->name = name;
		this->quantity = quantity;
		this->price = price;
	}

	Item(string lineFromFile) {
		istringstream inputString(lineFromFile);
		inputString >> name;
		inputString >> quantity;
		inputString >> price;
	}

	string getLineForFile() {
		return name + " " + to_string(quantity) + " " + to_string(price);
	}
};