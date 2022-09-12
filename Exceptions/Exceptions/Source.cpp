
#include <iostream>
#include "Cup.h"

using namespace std;

void validateNumberIsGreaterThan0(int number) {
	if (number < 0) {
		throw logic_error("Number can't be less than 0");
	}
}

int askForNumberGreaterThan0(string prompt) {
	int number = 0;

	while (number == 0) {
		cout << prompt << endl;
		cin >> number;
		try {
			validateNumberIsGreaterThan0(number);
		}
		// catch the type of error you expect to happen
		catch (logic_error exception) {
			cout << exception.what() << endl;
			number = 0;
		}
		
	}

	return number;
}

int main(){

	Cup cup = Cup("wood variety", 250, true, false, "wood", 150, "coffee");
	try {
		int milliliters;
		cout << "How much do you want to drink in milliliters?" << endl;
		cin >> milliliters;
		cup.drink(milliliters);
	}
	catch (logic_error exception) {
		cout << exception.what() << endl;
	}

	int length = askForNumberGreaterThan0("Please enter the length of your rectangle");
	int width = askForNumberGreaterThan0("Please enter the width of your rectangle");

	int area = length * width;

	cout << "The area of your rectangle is " << area << endl;
}