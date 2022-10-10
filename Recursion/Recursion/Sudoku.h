#pragma once

using namespace std;

#include <vector>
#include <algorithm>
#include <iostream>

class Sudoku {
private:

	const int MAX_INDEX = 9;

	vector<vector<int>> board;

	bool isSolved() {
		for (vector<int> row : board) {
			if (count(row.begin(), row.end(), 0) > 0) {
				return false;
			}
		}
		return true;
	}

	pair<int, int> getFirstOpenLocation() {
		for (int rowIndex = 0; rowIndex < MAX_INDEX; rowIndex++) {
			for (int columnIndex = 0; columnIndex < MAX_INDEX; columnIndex++) {
				if (board.at(rowIndex).at(columnIndex) == 0) {
					return pair<int,int> (rowIndex, columnIndex);
				}
			}
		}
		// bad default?
		return pair<int, int>(0, 0);
	}

	bool isValueUniqueInRow(int rowIndex, int value) {
		return count(board.at(rowIndex).begin(), board.at(rowIndex).end(), value) == 0;
	}

	bool isValueUniqueInColumn(int columnIndex, int value) {
		for (int rowIndex = 0; rowIndex < MAX_INDEX; rowIndex++) {
			if (board.at(rowIndex).at(columnIndex) == value) {
				return false;
			}
		}
		return true;
	}

	bool isValueUniqueInGrid(int rowIndex, int columnIndex, int value) {
		int startingRowIndex = rowIndex / 3;
		int startingColumnIndex = columnIndex / 3;

		for (int currentRowIndex = startingRowIndex * 3;
			currentRowIndex < startingRowIndex + 3;
			currentRowIndex++) {
			for (int currentColumnIndex = startingColumnIndex * 3;
				currentColumnIndex < startingColumnIndex + 3;
				currentColumnIndex++) {
				if (board.at(currentRowIndex).at(currentColumnIndex) == value) {
					return false;
				}
			}
		}

		return true;
	}

	bool canPlaceValue(int rowIndex, int columnIndex, int value) {
		return isValueUniqueInRow(rowIndex, value) &&
			isValueUniqueInColumn(columnIndex, value) &&
			isValueUniqueInGrid(rowIndex, columnIndex, value);
	}

public:
	Sudoku(vector<vector<int>> board) {
		this->board = board;
	}

	void solve() {
		if (!isSolved()) {
			pair<int, int> openIndexes = getFirstOpenLocation();
			for (int value = 1; value <= 9; value++) {
				if (canPlaceValue(openIndexes.first, openIndexes.second, value)) {
					board.at(openIndexes.first).at(openIndexes.second) = value;
					solve();
					// undo?
					if (!isSolved()) {
						board.at(openIndexes.first).at(openIndexes.second) = 0;
					}
				}
			}
		}
	}


	// should return a string instead for classes being classes
	void printBoard() {
		cout << "-------------------" << endl;
		for (vector<int> row : board) {
			cout << "|";
			for (int value : row) {
				cout << value << "|";
			}
			cout << endl << "-------------------" << endl;
		}
	}

};
