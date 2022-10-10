using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include "Sudoku.h"


int bettherFibNthHelper(int nth, int currentNth, int previous, int current) {
	if (nth == currentNth) {
		return current;
	}
	int next = previous + current;
	return (bettherFibNthHelper(nth, ++currentNth, current, next));
}

int betterFibNth(int nth) {
	// base cases
	if (nth <= 0) {
		return 0;
	}
	else if (nth == 1) {
		return 1;
	}
	return bettherFibNthHelper(nth, 2, 1, 1);
}

int fibNth(int nth) {
	// base cases
	if (nth <= 0){
		return 0;
	} else if ( nth == 1) {
		return 1;
	}
	return fibNth(nth - 1) + fibNth(nth - 2);
}

int fibLoop(int nth) {
	// base cases
	if (nth <= 0) {
		return 0;
	}
	else if (nth == 1) {
		return 1;
	}
	int currentNth = 2;
	int previous = 1;
	int current = 1;

	while (currentNth != nth) {
		int next = previous + current;
		previous = current;
		current = next;
		currentNth++;
	}

	return current;
}

void countDown(int value) {
	cout << value << endl;
	
	// base case - value is 0
	if (value > 0) {
		countDown(--value);
	}
	
}


void countDownWithoutRecursion(int value) {
	cout << value << endl;

	// base case - value is 0
	while (value > 0) {
		cout << --value << endl;
	}
}

int main() {
	//for (int nth = 0; nth < 45; nth++) {
	//	cout << betterFibNth(nth) << endl;
	//}

	vector<vector<int>> board = {
		{ 5, 3, 0, 0, 7, 0, 0, 0, 0 },
		{ 6, 0, 0, 1, 9, 5, 0, 0, 0 },
		{ 0, 9, 8, 0, 0, 0, 0, 6, 0 },
		{ 8, 0, 0, 0, 6, 0, 0, 0, 3 },
		{ 4, 0, 0, 8, 0, 3, 0, 0, 1 },
		{ 7, 0, 0, 0, 2, 0, 0, 0, 6 },
		{ 0, 6, 0, 0, 0, 0, 2, 8, 0 },
		{ 0, 0, 0, 4, 1, 9, 0, 0, 5 },
		{ 0, 0, 0, 0, 8, 0, 0, 7, 9 }
	};

	Sudoku sudoku(board);

	sudoku.printBoard();
	sudoku.solve();
	sudoku.printBoard();

	return 0;
}