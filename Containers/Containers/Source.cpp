#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

bool sortByLength(string first, string second) {
	return first.length() < second.length();
}

int main()
{
	vector<string> names;

	names.push_back("jeb");
	names.push_back("jenavieve");
	names.push_back("eric");
	names.push_back("jasmine");
	

	sort(names.begin(), names.end() );

	for (int index = 0; index < names.size(); index++) {
		cout << names.at(index) << endl;
	}

	sort(names.begin(), names.end(), sortByLength);

	for (string name : names) {
		name = "Test";
		cout << name << endl;
	}

	for (string name : names) {
		cout << name << endl;
	}

	for (string& name : names) {
		name = "Test";
		cout << name << endl;
	}

	list<int> lottoNumbers;
	lottoNumbers.push_front(10);
	lottoNumbers.push_back(20);
	lottoNumbers.push_front(5);
	lottoNumbers.push_back(30);

	// iterator are essentially pointers
	for (list<int>::iterator iterator = lottoNumbers.begin();
		iterator != lottoNumbers.end();
		iterator++) {
		cout << *iterator << endl;
	}

	cout << "Enter a number to add to the lotto ticket" << endl;
	int numberToAdd;
	cin >> numberToAdd;

	bool needToAddNumber = true;

	list<int>::iterator iterator = lottoNumbers.begin();
	while (iterator != lottoNumbers.end() && needToAddNumber) {
		if (numberToAdd < *iterator) {
			// insert is really fast - constant
			lottoNumbers.insert(iterator, numberToAdd);
			needToAddNumber = false;
		}
		// getting to the location to insert, not so fast
		// average of 1/2 N items
		iterator++;
	}

	if (needToAddNumber) {
		lottoNumbers.push_back(numberToAdd);
	}

	for (int number : lottoNumbers) {
		cout << number << endl;
	}

	map<string, double> grades;

	// add new key or it gets ignored
	grades.emplace("Jeb", 92.2);
	grades.emplace("Journey", 95.5);
	grades.emplace("Jenavieve", 75.9);
	grades.emplace("Jubilee", 83.9);

	// .at gives access for getting / setting
	cout << "Grade for Jeb " << grades.at("Jeb") << endl;
	grades.at("Jeb") = 100;
	cout << "Grade for Jeb " << grades.at("Jeb") << endl;

	map<int, int> sumCount;

	for (int sum = 2; sum <= 12; sum++) {
		sumCount.emplace(sum, 0);
	}

	cout << "How many rolls should we do?" << endl;
	double rollCount;
	cin >> rollCount;

	srand(time(0));

	for (int roll = 0; roll < rollCount; roll++) {
		int firstDie = rand() % 6 + 1;
		int secondDie = rand() % 6 + 1;
		int sum = firstDie + secondDie;
		sumCount.at(sum)++;
	}

	for (int sum = 2; sum <= 12; sum++) {
		cout << sum << ": " << sumCount.at(sum) / rollCount * 100 << "%" << endl;
	}

	for (map<int, int>::iterator iterator = sumCount.begin();
		iterator != sumCount.end();
		iterator++) {
		cout << "Key: " << iterator->first << " - Value: " << iterator->second << endl;
	}



}