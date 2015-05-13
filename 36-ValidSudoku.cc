/**
 * Determine if a Sudoku is valid
 *
 * The Sudoku board could be partially filled, where empty cells are
 * filled with the character '.'.
 *
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable.
 * Only the filled cells need to be validated.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char> >& board) {
		int sideLength = 9;
		// Check horizontal line
		for (int i = 0;i < sideLength;i++) {
			int tempCheck[9] = {0};
			for (int j = 0;j < sideLength;j++) {
				if (board[i][j] != '.') {
					if (tempCheck[board[i][j] - '1'] != 0)
						return false;
					else
						tempCheck[board[i][j] - '1'] = 1;
				}
			}
		}
		// Check vertical line
		for (int j = 0;j < sideLength;j++) {
			int tempCheck[9] = {0};
			for (int i = 0;i < sideLength;i++) {
				if (board[i][j] != '.') {
					if (tempCheck[board[i][j] - '1'] != 0)
						return false;
					else
						tempCheck[board[i][j] - '1'] = 1;
				}
			}
		}
		// Check small 3*3 line
		for (int i = 0;i < sideLength;i++) {
			int tempCheck[10] = {0};
			int startRow = (i / 3) * 3;
			int startCol = (i % 3) * 3;
			for (int j = 0;j < sideLength;j++) {
				int checkRow = startRow + j / 3;
				int checkCol = startCol + j % 3;
				if (board[checkRow][checkCol] != '.') {
					if (tempCheck[board[checkRow][checkCol] - '1'] != 0)
						return false;
					else
						tempCheck[board[checkRow][checkCol] - '1'] = 1;
				}
			}
		}
		return true;
	}
};

