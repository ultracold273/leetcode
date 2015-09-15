/**
 * Given a m x n matrix, if an element is 0, 
 * set its entire row and column to 0. Do it in place.
 *
 * Follow up:
 *
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, 
 * but still not the best solution.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int> > & matrix) {
		bool firstRow = false;
		bool firstCol = false;
		for (int i = 0;i < (int) matrix.size();i++) {
			for (int j = 0;j < (int) matrix[i].size();j++) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
					if (i == 0) firstRow = true;
					if (j == 0) firstCol = true;
				}
			}
		}

		for (int i = 1;i < (int) matrix.size();i++) {
			for (int j = 1;j < (int) matrix[i].size();j++) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
			}
		}

		if (firstRow) {
			for (int i = 0;i < (int)matrix[0].size();i++)
				matrix[0][i] = 0;
		}
		if (firstCol) {
			for (int i = 0;i < (int)matrix.size();i++)
				matrix[i][0] = 0;
		}
	}
};
