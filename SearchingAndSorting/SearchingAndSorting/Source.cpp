#include <iostream>
#include <vector>

// 3 10 21 23

// 3 10 15 21 23


// find 23

// start 2, end 3 - mid 2
// start 0, end 3 - mid 1

using namespace std;

void insertionSort(vector<int>& numbers) {
	for (int currentIndex = 1; currentIndex < numbers.size(); currentIndex++) {
		int indexToCheck = currentIndex;
		while (indexToCheck >= 1 && numbers.at(indexToCheck) < numbers.at(indexToCheck - 1)) {
			int temp = numbers.at(indexToCheck);
			numbers.at(indexToCheck) = numbers.at(indexToCheck - 1);
			numbers.at(indexToCheck - 1) = temp;
			indexToCheck--;

		}
	}
}


void selectionSort(vector<int>& numbers) {
	for (int currentIndex = 0; currentIndex < numbers.size(); currentIndex++) {
		int smallestIndex = currentIndex;
		for (int indexToCheck = currentIndex + 1; indexToCheck < numbers.size(); indexToCheck++) {
			if (numbers.at(indexToCheck) < numbers.at(smallestIndex) ){
				smallestIndex = indexToCheck;
			}
		}
		int temp = numbers.at(currentIndex);
		numbers.at(currentIndex) = numbers.at(smallestIndex);
		numbers.at(smallestIndex) = temp;
	}
}

// pre condition - somehting that is true before it runs
// post condition - something that is true after it runs

int recursiveBinarySearch(vector<int> numbers,
	int valueToFind, int startIndex = 0, int endIndex = -1) {
	if (endIndex == -1) {
		endIndex = numbers.size() - 1;
	}

	// base case - not found - maybe raise exception?
	if (endIndex < startIndex) {
		return -1;
	}

	int middleIndex = startIndex + ( ( endIndex - startIndex ) / 2 );

	if (numbers.at(middleIndex) == valueToFind) {
		return middleIndex;
	}
	else if (numbers.at(middleIndex) < valueToFind) {
		return recursiveBinarySearch(
			numbers, valueToFind, middleIndex + 1, endIndex);
	}
	else {
		return recursiveBinarySearch(
			numbers, valueToFind, startIndex, middleIndex - 1);
	}
}



int main() {
	vector<int> numbers = { 23, 10, 31, 3 };

	insertionSort(numbers);
	

	for (int number : numbers) {
		cout << "searching for " << number 
			<< " found at index: " 
			<< recursiveBinarySearch(numbers, number) 
			<< endl;
	}

	cout << "searching for 15"
		<< " found at index: "
		<< recursiveBinarySearch(numbers, 15)
		<< endl;

	return 0;
}