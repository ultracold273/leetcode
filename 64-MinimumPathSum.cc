/**
 * Given a m x n grid filled with non-negative numbers, 
 * find a path from top left to bottom right which minimizes 
 * the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int min(int a, int b) {
		return (a > b)?b:a;
	}

	int minPathSum(vector<vector<int> >& grid) {
		int m = grid.size();
		int n = grid[0].size();
		for (int i = m - 1;i >= 0;i--) {
			for (int j = n - 1;j >= 0;j--) {
//				cout << i << ":" << j << endl;
				if (i == m - 1 && j == n - 1) {
					continue;
				}
				if (i + 1 <= m - 1 && j + 1 <= n - 1) {
					grid[i][j] = min(grid[i + 1][j], grid[i][j + 1]) + grid[i][j];
				}
				else if (i + 1 > m - 1)
					grid[i][j] = grid[i][j + 1] + grid[i][j];
				else 
					grid[i][j] = grid[i + 1][j] + grid[i][j];
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

};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	vector<vector<int> > vecObstacle;
	int a[3][3] = {{0,0,0}, {0,1,-1}, {0,0,0}};
	vecObstacle.push_back(vector<int> (a[0], a[0] + 3));
	vecObstacle.push_back(vector<int> (a[1], a[1] + 3));
	vecObstacle.push_back(vector<int> (a[2], a[2] + 3));
	cout << sol->minPathSum(vecObstacle) << endl;
	return 0;
}
