/**
 * Given an integer n, generate a square matrix filled 
 * with elements from 1 to n^2 in spiral order.
 * 
 * For example,
 * Given n = 3,
 * You should return the following matrix:
 * [
 * 	 [ 1, 2, 3 ],
 * 	 [ 8, 9, 4 ],
 * 	 [ 7, 6, 5 ]
 * ]
 */

#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int> >& matrix);

class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> > matrix;
		for (int i = 0;i < n;i++) {
			vector<int> aRow (n, 0);
			matrix.push_back(aRow);
		}
		printMatrix(matrix);
		int dirX[4] = {0, 1, 0, -1};
		int dirY[4] = {1, 0, -1, 0};
		int dirIdx = 0;
		int x = 0;
		int y = 0;
		int lineCount = 0;
		int lineMax[2];
		lineMax[0] = n; lineMax[1] = n - 1;
		for (int i = 0;i < n * n;i++) {
			matrix[x][y] = i + 1;
			x += dirX[dirIdx];
			y += dirY[dirIdx];
			lineCount++;
			if (lineCount == lineMax[dirIdx % 2]) {
				x -= dirX[dirIdx];
				y -= dirY[dirIdx];
				lineMax[dirIdx % 2]--;
				dirIdx++;
				if (dirIdx == 4) dirIdx = 0;
				x += dirX[dirIdx];
				y += dirY[dirIdx];
				lineCount = 0;
			}
		}
		return matrix;
	}
};

void printMatrix(vector<vector<int> > &matrix) {
	cout << '[' << endl;
	for (int i = 0;i < (int) matrix.size();i++) {
		cout << "\t[ ";
		for (int j = 0;j < (int) matrix[i].size();j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << ']' << endl;
	}
	cout << ']' << endl;
}

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	vector<vector<int> > spiralMat = sol->generateMatrix(6);
	printMatrix(spiralMat);
	return 0;
}
