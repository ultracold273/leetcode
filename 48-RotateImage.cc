/**
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 * 
 * Follow up:
 * Could you do this in-place?
 */

#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int> > &nums) {
	cout << "[" << endl;
	for (int i = 0; i < nums.size(); ++i) {
		cout << "\t[ ";
		for (int j = 0; j < nums[i].size(); ++j) {
			cout << nums[i][j] << " ";
		}	
		cout << "]" << endl; 
	}
	cout << "]" << endl;
}


class Solution {
public:
	void rotate(vector<vector<int> >& matrix) {
		int dims = matrix.size();
		for (int i = 0;i < dims / 2;i++) {
			for (int j = i;j < dims - 1 - i;j++) {
				int temp = matrix[i][j];
				matrix[i][j] = matrix[dims - j - 1][i];
				matrix[dims - j - 1][i] = matrix[dims - i - 1][dims - j - 1];
				matrix[dims - i - 1][dims - j - 1] = matrix[j][dims - i - 1];
				matrix[j][dims - i - 1] = temp;
			}
		}

	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	vector<vector<int> > matrix (3, vector<int>(3));
	for (int i = 0; i < 3 * 3; ++i) {
		matrix[i/3][i%3] = i;
	}
	printMatrix(matrix);
	sol->rotate(matrix);
	printMatrix(matrix);
	return 0;
}