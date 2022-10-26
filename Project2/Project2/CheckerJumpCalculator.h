#pragma once

using namespace std;

#include <vector>

class CheckerJumpCalculator {
private:
	const char WHITE = 'W';
	const char BLACK = 'B';
	const char EMPTY = ' ';

	vector<vector<char>> board;
	int maxNumberOfJumps;
	int currentNumberOfJumps;

	bool canJumpUpRight(int rowIndex, int columnIndex) {
		return rowIndex - 2 >= 0 &&
			columnIndex + 2 < board.at(rowIndex - 2).size() &&
			board.at(rowIndex - 2).at(columnIndex + 2) == EMPTY &&
			board.at(rowIndex - 1).at(columnIndex + 1) == BLACK;
	}

	bool canJumpUpLeft(int rowIndex, int columnIndex) {
		return rowIndex - 2 >= 0 &&
			columnIndex - 2 >= 0 &&
			board.at(rowIndex - 2).at(columnIndex - 2) == EMPTY &&
			board.at(rowIndex - 1).at(columnIndex - 1) == BLACK;
	}

	bool canJumpDownLeft(int rowIndex, int columnIndex) {
		return rowIndex + 2 < board.size() &&
			columnIndex - 2 >= 0 &&
			board.at(rowIndex + 2).at(columnIndex - 2) == EMPTY &&
			board.at(rowIndex + 1).at(columnIndex - 1) == BLACK;
	}

	bool canJumpDownRight(int rowIndex, int columnIndex) {
		return rowIndex + 2 < board.size() &&
			columnIndex + 2 < board.at(rowIndex+2).size() &&
			board.at(rowIndex + 2).at(columnIndex + 2) == EMPTY &&
			board.at(rowIndex + 1).at(columnIndex + 1) == BLACK;
	}


	void getMaxJumps(int rowIndex, int columnIndex) {
		if (currentNumberOfJumps > maxNumberOfJumps) {
			maxNumberOfJumps = currentNumberOfJumps;
		}

		if (canJumpUpRight(rowIndex, columnIndex)) {
			currentNumberOfJumps++;
			board.at(rowIndex).at(columnIndex) = EMPTY;
			board.at(rowIndex - 1).at(columnIndex + 1) = EMPTY;
			board.at(rowIndex - 2).at(columnIndex + 2) = WHITE;
			getMaxJumps(rowIndex - 2, columnIndex + 2);
			board.at(rowIndex - 2).at(columnIndex + 2) = EMPTY;
			board.at(rowIndex - 1).at(columnIndex + 1) = BLACK;
			board.at(rowIndex).at(columnIndex) = WHITE;
			currentNumberOfJumps--;
		}
		if (canJumpUpLeft(rowIndex, columnIndex)) {
			currentNumberOfJumps++;
			board.at(rowIndex).at(columnIndex) = EMPTY;
			board.at(rowIndex - 1).at(columnIndex - 1) = EMPTY;
			board.at(rowIndex - 2).at(columnIndex - 2) = WHITE;
			getMaxJumps(rowIndex - 2, columnIndex - 2);
			board.at(rowIndex - 2).at(columnIndex - 2) = EMPTY;
			board.at(rowIndex - 1).at(columnIndex - 1) = BLACK;
			board.at(rowIndex).at(columnIndex) = WHITE;
			currentNumberOfJumps--;
		}
		if (canJumpDownLeft(rowIndex, columnIndex)) {
			currentNumberOfJumps++;
			board.at(rowIndex).at(columnIndex) = EMPTY;
			board.at(rowIndex + 1).at(columnIndex - 1) = EMPTY;
			board.at(rowIndex + 2).at(columnIndex - 2) = WHITE;
			getMaxJumps(rowIndex + 2, columnIndex - 2);
			board.at(rowIndex + 2).at(columnIndex - 2) = EMPTY;
			board.at(rowIndex + 1).at(columnIndex - 1) = BLACK;
			board.at(rowIndex).at(columnIndex) = WHITE;
			currentNumberOfJumps--;
		}
		if (canJumpDownRight(rowIndex, columnIndex)) {
			currentNumberOfJumps++;
			board.at(rowIndex).at(columnIndex) = EMPTY;
			board.at(rowIndex + 1).at(columnIndex + 1) = EMPTY;
			board.at(rowIndex + 2).at(columnIndex + 2) = WHITE;
			getMaxJumps(rowIndex + 2, columnIndex + 2);
			board.at(rowIndex + 2).at(columnIndex + 2) = EMPTY;
			board.at(rowIndex + 1).at(columnIndex + 1) = BLACK;
			board.at(rowIndex).at(columnIndex) = WHITE;
			currentNumberOfJumps--;
		}
	}

public:
	CheckerJumpCalculator(vector<vector<char>> board) {
		this->board = board;
		maxNumberOfJumps = 0;
		currentNumberOfJumps = 0;
	}

	int getMaxJumps() {
		for (int rowIndex = 0; rowIndex < board.size(); rowIndex++) {
			for (int columnIndex = 0;
				columnIndex < board.at(rowIndex).size(); columnIndex++) {
				if (board.at(rowIndex).at(columnIndex) == WHITE) {
					currentNumberOfJumps = 0;
					getMaxJumps(rowIndex, columnIndex);
				}
			}
		}

		return maxNumberOfJumps;
	}

};