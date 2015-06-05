/**
 * Follow up for "Unique Paths":
 *
 * Now consider if some obstacles are added to the grids. 
 * How many unique paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively 
 * in the grid.
 *
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 * The total number of unique paths is 2.
 *
 * Note: m and n will be at most 100.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		for (int i = m - 1;i >= 0;i--) {
			for (int j = n - 1;j >= 0;j--) {
//				cout << i << ":" << j << endl;
				if (obstacleGrid[i][j] == 1) {
					obstacleGrid[i][j] = 0;
					continue;
				}
				if (i == m - 1 && j == n - 1) {
					obstacleGrid[i][j] = -1;
					continue;
				}
				if (i + 1 <= m - 1 && j + 1 <= n - 1)
					obstacleGrid[i][j] = obstacleGrid[i + 1][j] + obstacleGrid[i][j + 1];
				else if (i + 1 > m - 1)
					obstacleGrid[i][j] = obstacleGrid[i][j + 1];
				else 
					obstacleGrid[i][j] = obstacleGrid[i + 1][j];
			}
		}
		
//		for (int i = 0;i < m;i++) {
//			for (int j = 0;j < n;j++) {
//				cout << obstacleGrid[i][j] << " ";
//			}
//			cout << endl;
//		}
		return -obstacleGrid[0][0];
	}

};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	vector<vector<int> > vecObstacle;
	int a[3][3] = {{0,0,0}, {0,1,0}, {0,0,0}};
	vecObstacle.push_back(vector<int> (a[0], a[0] + 3));
	vecObstacle.push_back(vector<int> (a[1], a[1] + 3));
	vecObstacle.push_back(vector<int> (a[2], a[2] + 3));
	cout << sol->uniquePathsWithObstacles(vecObstacle) << endl;
	return 0;
}
