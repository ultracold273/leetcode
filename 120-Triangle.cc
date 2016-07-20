/**
 * LeetCode 120 - Triangle
 * Given a triangle, find the minimum path sum from top to bottom. 
 * Each step you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 * The minimum path sum from top to bottom is 11 
 * (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Note:
 * Bonus point if you are able to do this using only O(n) extra space, 
 * where n is the total number of rows in the triangle.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal_rec(vector<vector<int> >& triangle, int row, int col) {
        int leftMini, rightMini;
        if (row == triangle.size() - 1) return triangle[row][col];
        else {
            leftMini = minimumTotal_rec(triangle, row + 1, col);
            rightMini = minimumTotal_rec(triangle, row + 1, col + 1);
            return triangle[row][col] + min(leftMini, rightMini);
        }
    }

    int minimumTotal_old(vector<vector<int> >& triangle) {
        return minimumTotal_rec(triangle, 0, 0);
    }

    /* Dynamic Programming */
    int minimumTotal(vector<vector<int> >& triangle) {
        vector<int> miniTotal(triangle[triangle.size() - 1]);
        for (int i = triangle.size() - 2;i >= 0;i--) {
            for (int j = 0;j < triangle[i].size();j++) {
                miniTotal[j] = min(miniTotal[j], miniTotal[j+1]) + triangle[i][j];
            }
        }
        return miniTotal[0];
    }
};
