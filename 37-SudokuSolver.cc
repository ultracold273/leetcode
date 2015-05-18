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

void printBoard(vector<vector<char> > &board) {
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

void printVector(vector<int> &vecInt) {
	for(int i = 0;i < vecInt.size();i++) {
		cout << vecInt[i] << ' ';
	}
	cout << endl;
}

class Solution {
public:
	bool isValidSudokuCube(vector<vector<char> > &board, int row, int col) {
		int tempCheck[9] = {0};
		int startRow = row - row % 3;
		int startCol = col - col % 3;
		for (int i = 0;i < 9;i++) {
			int checkRow = startRow + i / 3;
			int checkCol = startCol + i % 3;
			if (board[checkRow][checkCol] != '.') {
				if (tempCheck[board[checkRow][checkCol] - '1'] != 0)
					return false;
				else
					tempCheck[board[checkRow][checkCol] - '1'] = 1;
			}
		}
		return true;
	}

	bool isValidSudokuCol(vector<vector<char> > &board, int col) {
		int tempCheck[9] = {0} ;
		for (int i = 0;i < 9;i++) {
			if(board[i][col] != '.') {
				if(tempCheck[board[i][col] - '1'] != 0) 
					return false;
				else
					tempCheck[board[i][col] - '1'] = 1;
			}
		}
		return true;
	}

	void solveSudoku(vector<vector<char> >& board) {
		if(solveSudokuRec(board, 0, 0))
			return;
		else
			cerr << "Not solvable." << endl;
	}

	vector<int> findLeftNumberInRow(vector<vector<char> > &board, int row) {
		int tempCheck[9] = {0};
		for (int i = 0;i < 9;i++) {
			if(board[row][i] != '.') {
				tempCheck[board[row][i] - '1'] = 1;
			}
		}
		vector<int> leftNum;
		for (int i = 0;i < 9;i++) {
			if(tempCheck[i] == 0) {
				leftNum.push_back(i);
			}
		}
		return leftNum;
	}

	bool solveSudokuRec(vector<vector<char> > &board, int row, int col) {
		int nextRow, nextCol;
		nextRow = row;nextCol = col;
		bool detectNextFlag = false;
		while(nextRow != 9) {
			if (board[nextRow][nextCol] == '.') {
				detectNextFlag = true;
				break;
			}
			nextCol++;
			if (nextCol == 9) {
				nextCol = 0;
				nextRow++;
			}
		}
		/*
		for(nextRow = row;nextRow < 9;nextRow++) {
			for(nextCol = col;nextCol < 9;nextCol++) {
				if (board[nextRow][nextCol] == '.') {
					detectNextFlag = true;
					break;
				}
			}
			if(detectNextFlag) break;
		}
		*/
		if (!detectNextFlag) return true;
//		cout << nextRow << ' ' << nextCol << endl;
//		printBoard(board);
		vector<int> leftNumber = findLeftNumberInRow(board, nextRow);
//		printVector(leftNumber);
		for(int i = 0;i < (int) leftNumber.size();i++) {
			board[nextRow][nextCol] = leftNumber[i] + '1';
			if (!isValidSudokuCol(board, nextCol)) continue;
			if (!isValidSudokuCube(board, nextRow, nextCol)) continue;
			if (solveSudokuRec(board, nextRow, nextCol))
				return true;
		}
		board[nextRow][nextCol] = '.';
		return false;
	}
};

int main(int argc, char *argv[]) {
	Solution * sol = new Solution();
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
	printBoard(board);

	sol->solveSudoku(board);
	
	// Printing Sudoku
	printBoard(board);
}
