/**
 * Follow up for N-Queens problem.
 *
 * Now, instead outputting board configurations, 
 * return the total number of distinct solutions.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
		int res = 0;
		vector<int> board (n, -1);
		if (n == 1) return 1;
		for (int i = 0;i < n;i++) {
			recNQueenPlacer(board, n, 0, i, res);
		}
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

	void recNQueenPlacer(vector<int> &board, int n, int row, int col, int & res) {
		board[row] = col;
		vector<int> avaiPos = findAvailablePos(board, n, row + 1);
//		cout << "row: "<< row << endl;
//		printVec(avaiPos);
		if(row == n - 2) {
			res += (int) avaiPos.size();
			return;
		}else{
			for (int j = 0;j < (int) avaiPos.size();j++) {
				recNQueenPlacer(board, n, row + 1, avaiPos[j], res);
			}
		}
	}
};

