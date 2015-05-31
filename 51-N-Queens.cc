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

class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<vector<string> > res;
		return res;
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	vector<vector<string> > solvedNQueens;
	solvedNQueens = sol->solveNQueens(2);
	printNQueen(solvedNQueens);
	solvedNQueens = sol->solveNQueens(3);
	printNQueen(solvedNQueens);
	solvedNQueens = sol->solveNQueens(4);
	printNQueen(solvedNQueens);
	solvedNQueens = sol->solveNQueens(5);
	printNQueen(solvedNQueens);
	solvedNQueens = sol->solveNQueens(6);
	printNQueen(solvedNQueens);
	solvedNQueens = sol->solveNQueens(7);
	printNQueen(solvedNQueens);
	solvedNQueens = sol->solveNQueens(8);
	printNQueen(solvedNQueens);
}
