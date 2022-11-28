#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

#include "Item.h"

using namespace std;


void firstExamples() {
	string fileName;

	cout << "Enter the name of a file to create" << endl;

	cin >> fileName;

	ofstream fileOutput;
	fileOutput.open(fileName);

	ofstream anotherFileOutput;
	anotherFileOutput.open(fileName + "2.txt");

	if (!fileOutput.is_open()) {
		cout << "Unable to open file, please try again!" << endl;
	}
	else {
		fileOutput << "Happy Thanksgiving!" << endl;
		fileOutput << "45 to 23, sportsball!" << endl;

		anotherFileOutput << "Here's another file!" << endl;

		fileOutput.close();
		anotherFileOutput.close();
	}

	ofstream lottoFileOutput;
	lottoFileOutput.open("lottoNumbers.txt");

	if (!lottoFileOutput.is_open()) {
		cout << "Unable to open file, please try again!" << endl;
	}
	else {
		vector<int> numbers;

		srand(time(0));
		numbers.push_back(rand() % 69 + 1);

		while (numbers.size() != 5) {
			int randomNumber = rand() % 69 + 1;
			if (find(numbers.begin(), numbers.end(), randomNumber) == numbers.end()) {
				numbers.push_back(randomNumber);
			}
		}

		numbers.push_back(rand() % 26 + 1);

		for (int number : numbers) {
			lottoFileOutput << number << endl;
		}

		lottoFileOutput.close();

	}

	ifstream inputFile;

	inputFile.open("lottoNumbers.txt");

	if (!inputFile.is_open()) {
		cout << "Could not open file" << endl;
		return;
	}

	vector<int> winningNumbers;

	int number;
	inputFile >> number;
	while (!inputFile.fail()) {
		winningNumbers.push_back(number);
		inputFile >> number;
	}
	if (!inputFile.eof()) {
		cout << "Input failure before reaching end of file." << endl;
	}

	inputFile.close();

	for (int number : winningNumbers) {
		cout << number << endl;
	}
}

int main() {

	const string wishListName = "wishList.txt";

	ifstream inputFile;

	inputFile.open(wishListName);

	vector<Item> wishList;

	string line;
	getline(inputFile, line);

	cout << "Current Wish List:" << endl;
	while (!inputFile.fail()) {
		wishList.push_back(Item(line));
		cout << line << endl;
		getline(inputFile, line);
	}
	if (!inputFile.eof()) {
		cout << "Input failure before reaching end of file." << endl;
	}

	inputFile.close();


	string input;

	cout << "Do you want to add more items to your wish list? (y/n)" << endl;


	cin >> input;

	while (input == "y") {
		string itemName;
		cout << "Enter the item name:" << endl;
		cin >> itemName;

		int quantity;
		cout << "Enter the item quantity:" << endl;
		cin >> quantity;

		double price;
		cout << "Enter the item price:" << endl;
		cin >> price;

		Item item(itemName, quantity, price);

		wishList.push_back(item);

		cout << "Do you want to add more items to your wish list? (y/n)" << endl;

		cin >> input;
	}


	ofstream fileOutput;
	fileOutput.open(wishListName);

	for (Item item : wishList ) {
		fileOutput << item.getLineForFile() << endl;
	}
	fileOutput.close();
}
