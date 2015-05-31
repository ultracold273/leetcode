/**
 * The n-queens puzzle is the problem of placing n queens on an nxn 
 * chessboard such that no two queens attack each other.
 *
 * Given an integer n, 
 * return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the 
 * n-queens' placement, 
 * where 'Q' and '.' both indicate a queen and an empty space respectively.
 *
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 *
 * [
 *  [".Q..",  // Solution 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],
 *
 *  ["..Q.",  // Solution 2
 *   "Q...",
 *   "...Q",
 *   ".Q.."]
 * ]
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printNQueen(vector<vector<string> > &board) {
	cout << '[' << endl;
	for (int i = 0;i < (int) board.size();i++) {
		for (int j = 0;j < (int) board[i].size();j++) {
			cout << "\t";
			(j == 0)?cout << "[":cout << " ";
			cout << board[i][j];
			(j == (int) board[i].size() - 1)?cout << "]":cout << ",";
			cout << endl;
		}
	}
	cout << ']' << endl;
}

void printVec(vector<int> &vec) {
	cout << "[";
	for (int i = 0;i < (int)vec.size();i++) {
		cout << vec[i] << " ";
	}
	cout << "]" << endl;
}

class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<vector<string> > res;
		vector<int> board (n, -1);
		if (n == 1) {
			vector<string> boardStr (1, "Q");
			res.push_back(boardStr);
		}else {
			for (int i = 0;i < n;i++) {
				recNQueenPlacer(board, n, 0, i, res);
			}
		}
//		res.push_back(board);
		return res;
	}

	vector<int> findAvailablePos(vector<int> &board, int n, int row) {
		vector<bool> unAvailable (n, false);
		vector<int> availableCol;
		for(int i = 0;i < row;i++) {
			int col = board[i];
			// check vertical
			if (!unAvailable[col]) unAvailable[col] = true;
			// check diagonal
			int diag1 = i + col - row;
			int diag2 = row - i + col;
			if (diag1 >= 0) {
				if (!unAvailable[diag1]) unAvailable[diag1] = true;
			}
			if (diag2 < n) {
				if (!unAvailable[diag2]) unAvailable[diag2] = true;
			}
		}
		for (int i = 0;i < n;i++) {
			if (!unAvailable[i])
				availableCol.push_back(i);
		}
		return availableCol;
	}

	vector<string> makeBoardStr(vector<int> &board, int n) {
		vector<string> boardStr (n, string(n, '.'));
		for (int i = 0;i < n;i++) {
			boardStr[i][board[i]] = 'Q';
		}
		return boardStr;
	}

	void recNQueenPlacer(vector<int> &board, int n, int row, int col, vector<vector<string> > & res) {
		board[row] = col;
		vector<int> avaiPos = findAvailablePos(board, n, row + 1);
//		cout << "row: "<< row << endl;
//		printVec(avaiPos);
		if(row == n - 2) {
			for (int j = 0;j < (int) avaiPos.size();j++) {
				board[row + 1] = avaiPos[j];
				vector<string> boardStr = makeBoardStr(board, n);
				res.push_back(boardStr);
			}
			return;
		}else{
			for (int j = 0;j < (int) avaiPos.size();j++) {
				recNQueenPlacer(board, n, row + 1, avaiPos[j], res);
			}
		}
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	vector<vector<string> > solvedNQueens;
	cout << "2-Queens:" << endl;
	solvedNQueens = sol->solveNQueens(2);
	printNQueen(solvedNQueens);
//	solvedNQueens = sol->solveNQueens(3);
//	printNQueen(solvedNQueens);
	cout << "4-Queens:" << endl;
	solvedNQueens = sol->solveNQueens(4);
	printNQueen(solvedNQueens);
//	solvedNQueens = sol->solveNQueens(5);
//	printNQueen(solvedNQueens);
	cout << "6-Queens:" << endl;
	solvedNQueens = sol->solveNQueens(6);
	printNQueen(solvedNQueens);
//	solvedNQueens = sol->solveNQueens(7);
//	printNQueen(solvedNQueens);
	cout << "8-Queens:" << endl;
	solvedNQueens = sol->solveNQueens(8);
	printNQueen(solvedNQueens);
}
