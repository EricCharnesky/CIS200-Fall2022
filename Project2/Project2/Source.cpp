#include <vector>
#include "CheckerJumpCalculator.h"
#include <iostream>

using namespace std;

int main()
{
	vector<vector<char>> board = {
		{'B', ' ', 'B', ' ', ' ', ' ', ' ', ' '},
		{' ', 'W', ' ', 'W', ' ', ' ', ' ', ' '},
		{'B', ' ', 'B', ' ', 'B', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', 'B', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', 'B', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
	};

	CheckerJumpCalculator checkerJumpCalculator(board);
	cout << "Max jumps: " << checkerJumpCalculator.getMaxJumps() << endl;
}