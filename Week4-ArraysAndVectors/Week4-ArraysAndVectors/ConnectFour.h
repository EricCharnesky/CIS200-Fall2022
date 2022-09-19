#pragma once

using namespace std;

#include <vector>

class ConnectFour {
private:
	char currentPlayer;
	vector<vector<char>> board;

	bool hasWinnerVertically() {
		for (int columnIndex = 0; columnIndex < board.at(0).size(); columnIndex++) {
			for (int rowIndex = 0; rowIndex <= 2; rowIndex++) {
				if (board.at(rowIndex).at(columnIndex) != ' ' &&
					board.at(rowIndex).at(columnIndex) == board.at(rowIndex + 1).at(columnIndex) &&
					board.at(rowIndex).at(columnIndex) == board.at(rowIndex + 2).at(columnIndex) &&
					board.at(rowIndex).at(columnIndex) == board.at(rowIndex + 3).at(columnIndex)) {
					return true;
				}
			}
		}
		return false;
	}

	bool hasWinnerHoiztontally() {
		for (int rowIndex = 0; rowIndex < board.size(); rowIndex++) {
			for (int columnIndex = 0; columnIndex <= 3; columnIndex++) {
				if (board.at(rowIndex).at(columnIndex) != ' ' &&
					board.at(rowIndex).at(columnIndex) == board.at(rowIndex).at(columnIndex + 1 ) &&
					board.at(rowIndex).at(columnIndex) == board.at(rowIndex).at(columnIndex + 2 ) &&
					board.at(rowIndex).at(columnIndex) == board.at(rowIndex).at(columnIndex + 3 )) {
					return true;
				}
			}
		}
		return false;
	}

	bool hasWinnerDiagonllyUp() {
		for (int rowIndex = board.size() - 1; rowIndex >= 3; rowIndex--) {
			for (int columnIndex = 0; columnIndex <= 3; columnIndex++) {
				if (board.at(rowIndex).at(columnIndex) != ' ' &&
					board.at(rowIndex).at(columnIndex) == board.at(rowIndex - 1).at(columnIndex + 1) &&
					board.at(rowIndex).at(columnIndex) == board.at(rowIndex - 2).at(columnIndex + 2) &&
					board.at(rowIndex).at(columnIndex) == board.at(rowIndex - 3).at(columnIndex + 3)) {
					return true;
				}
			}
		}
		return false;
	}

	bool hasWinnerDiagonllyDown() {
		for (int rowIndex = 0; rowIndex <= 2; rowIndex++) {
			for (int columnIndex = 0; columnIndex <= 3; columnIndex++) {
				if (board.at(rowIndex).at(columnIndex) != ' ' &&
					board.at(rowIndex).at(columnIndex) == board.at(rowIndex + 1).at(columnIndex + 1) &&
					board.at(rowIndex).at(columnIndex) == board.at(rowIndex + 2).at(columnIndex + 2) &&
					board.at(rowIndex).at(columnIndex) == board.at(rowIndex + 3).at(columnIndex + 3)) {
					return true;
				}
			}
		}
		return false;
	}

	bool hasWinnerDiagonally() {
		return hasWinnerDiagonllyDown() || hasWinnerDiagonllyUp();
	}

	bool boardIsFull() {
		for (int rowIndex = 0; rowIndex < board.size(); rowIndex++) {
			for (int columnIndex = 0; columnIndex < board.at(rowIndex).size(); columnIndex++) {
				if (board.at(rowIndex).at(columnIndex) == ' '){
					return false;
				}
			}
		}
		return true;
	}
	
public:
	ConnectFour() {
		currentPlayer = 'X';

		for (int rowIndex = 0; rowIndex < 6; rowIndex++) {
			vector<char> row(7, ' ');
			board.push_back(row);
		}
	}

	bool dropPiece(int columnIndex) {
		if (columnIndex < 0 || columnIndex >= board.at(0).size()) {
			return false;
		}

		for (int rowIndex = board.size() - 1; rowIndex >= 0; rowIndex--) {
			if (board.at(rowIndex).at(columnIndex) == ' ') {
				board.at(rowIndex).at(columnIndex) = currentPlayer;
				currentPlayer = currentPlayer == 'X' ? 'O' : 'X';
				return true;
			}
		}
		return false;
	}

	char getCurrentPlayer() {
		return currentPlayer;
	}

	vector<vector<char>> getBoard() {
		vector<vector<char>> boardCopy(board);
		return boardCopy;
	}

	bool isGameOver() {
		return hasWinnerVertically() || hasWinnerHoiztontally() ||
			hasWinnerDiagonally() || boardIsFull();
	}

};
