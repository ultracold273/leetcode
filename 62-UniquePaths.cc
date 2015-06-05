/**
 * A robot is located at the top-left corner of a m x n grid 
 * (marked 'Start' in the diagram below).
 *
 * The robot can only move either down or right at any point in time. 
 * The robot is trying to reach the bottom-right corner of the grid 
 * (marked 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 *
 * Note: m and n will be at most 100.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		int ** grid = new int*[m];
		for (int i = 0;i < m;i++) grid[i] = new int[n];

		for (int i = m - 1;i >= 0;i--) {
			for (int j = n - 1;j >= 0;j--) {
//				cout << i << ":" << j << endl;
				if (i == m - 1 && j == n - 1) {
					grid[i][j] = 1;
					continue;
				}
				if (i + 1 <= m - 1 && j + 1 <= n - 1)
					grid[i][j] = grid[i + 1][j] + grid[i][j + 1];
				else if (i + 1 > m - 1)
					grid[i][j] = grid[i][j + 1];
				else 
					grid[i][j] = grid[i + 1][j];
			}
		}
		
//		for (int i = 0;i < m;i++) {
//			for (int j = 0;j < n;j++) {
//				cout << grid[i][j] << " ";
//			}
//			cout << endl;
//		}
		return grid[0][0];
	}

	int uniquePaths_rec(int m, int n) {
		if (m <= 0 || n <= 0) return 0;
		if (m == 1 && n == 1) return 2;
		else if (m == 1 || n == 1) return 1;
		else {
			return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
		}
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	cout << sol->uniquePaths(10, 1) << endl;
	return 0;
}
