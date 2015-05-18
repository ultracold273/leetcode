/** 
 * LeetCode 37 -- Sudoku Solver
 *
 * Write a program to solve Sudoku puzzle by filling the empty cells.
 *
 * Empty cells are indicated by the character '.'.
 *
 * You may assume that there will be only one unique solution.
 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char> >& board) {
	}
};

int main(int argc, char *argv[]) {
	Solution * sol = new Solution;
	char a[9][9];
	strncpy(a[0], "53..7....", 9);
	strncpy(a[1], "6..195...", 9);
	strncpy(a[2], ".98....6.", 9);
	strncpy(a[3], "8...6...3", 9);
	strncpy(a[4], "4..8.3..1", 9);
	strncpy(a[5], "7...2...6", 9);
	strncpy(a[6], ".6....28.", 9);
	strncpy(a[7], "...419..5", 9);
	strncpy(a[8], "....8..79", 9);
	
	vector<vector<char> > board;
	for (int i = 0;i < 9;i++) {
		vector<char> aVec (a[i], a[i] + 9);
		board.push_back(aVec);
	}

	// Printing Sudoku
	for (int i = 0;i < 9;i++) {
		if (i % 3 == 0) {
			for (int j = 0;j < 9 * 2 + 1;j++) {
				cout << '-';
			}
			cout << endl;
		}
		cout << '|';
		for (int j = 0;j < 9;j++) {
			cout << board[i][j]; 
			if (j % 3 == 2) {
				cout << '|';
			}else{
				cout << ' ';
			}
		}
		cout << endl;
	}
	for (int j = 0;j < 9 * 2 + 1;j++) {
		cout << '-';
	}
	cout << endl;
}
