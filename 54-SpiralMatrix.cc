/**
 * Given a matrix of m x n elements (m rows, n columns), return all
 * elements of the matrix in spiral order.
 *
 * For example,
 * Given the following matrix:
 * [
 *  [1, 2, 3],
 *  [4, 5, 6],
 *  [7, 8, 9],
 * ]
 * You should return [1, 2, 3, 6, 9, 8, 7, 4, 5]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> >& matrix) {
		int totalRow = matrix.size();
		vector<int> spiralOut;
		if (totalRow == 0) return spiralOut;
		int totalCol = matrix[0].size();
		int dirX[4] = {0, 1, 0, -1};
		int dirY[4] = {1, 0, -1, 0};
		int dirIdx = 0;
		int elements[2];
		elements[0] = totalCol;
		elements[1] = totalRow - 1;
		int x = 0;
		int y = 0;
		int j = 0;
		for (int i = 0;i < totalCol * totalRow;i++) {
			spiralOut.push_back(matrix[x][y]);
			x += dirX[dirIdx];
			y += dirY[dirIdx];
			j++;
			if(j >= elements[dirIdx % 2]) {
				elements[dirIdx % 2]--;
				x -= dirX[dirIdx];
				y -= dirY[dirIdx];
				dirIdx++;
				if (dirIdx == 4) dirIdx = 0;
				j = 0;
				x += dirX[dirIdx];
				y += dirY[dirIdx];
			}
		}
		return spiralOut;
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	int a[3][3];
	for (int i = 0;i < 9;i++) {
		*(a[0] + i) = i + 1;
	}
	vector<vector<int> > matrix;
	for (int i = 0;i < 3;i++) {
		vector<int> t (a[i], a[i] + 3);
		matrix.push_back(t);
	}

	for (int i = 0;i < matrix.size();i++) {
		cout << "[ ";
		for (int j = 0;j < matrix[i].size();j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << "]" << endl;
	}
	cout << endl;

	vector<int> res = sol->spiralOrder(matrix);

	for (int i = 0;i < res.size();i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}
