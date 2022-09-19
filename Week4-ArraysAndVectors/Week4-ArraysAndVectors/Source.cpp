using namespace std;

#include <iostream>
#include <vector>
#include "ConnectFour.h"

void printBoard(ConnectFour& game)
{
	vector<vector<char>> board = game.getBoard();
	for (int rowIndex = 0; rowIndex < board.size(); rowIndex++) {
		cout << "---------------" << endl;
		for (int columnIndex = 0; columnIndex < board.at(rowIndex).size(); columnIndex++) {
			cout << "|" << board.at(rowIndex).at(columnIndex);
		}
		cout << "|" << endl;
	}
	cout << "---------------" << endl;
}

int main() {

	cout << "How many numbers do you want to store?" << endl;
	int numberOfValues;
	cin >> numberOfValues;

	int* values = new int[numberOfValues];

	for (int index = 0; index < numberOfValues; index++) {
		values[index] = index;
	}

	int* currentValue = values;

	for (int index = 0; index < 15; index++) {
		cout << "At memory address: " << currentValue << ": " 
			<< *currentValue << endl;
		currentValue++;
	}

	vector<int> numbers(numberOfValues, 0);

	for (int index = 0; index < numbers.size(); index++) {
		numbers.at(index) = index;
	}

	numbers.push_back(42);

	for (int index = 0; index < numbers.size(); index++) {
		cout << numbers.at(index) << endl;
	}

	// vectors will throw an exception if you access an invalid index
	/*for (int index = 0; index < 15; index++) {
		cout << numbers.at(index) << endl;
	}*/


	ConnectFour game;

	while (!game.isGameOver()) {

		printBoard(game);

		cout << game.getCurrentPlayer() << "'s turn" << endl;
		cout << "Enter the column index you want to drop a piece in" << endl;
		int columnIndex;
		cin >> columnIndex;
		game.dropPiece(columnIndex);
	}

	printBoard(game);
}