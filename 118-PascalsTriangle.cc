/**
 * LeetCode 118 - Pascal's Triangle
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 * Return
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        for(int i = 0;i < numRows;i++) {
            vector<int> row;
            for(int j = 0;j <= i;j++) {
                if (j == 0 || j == i) row.push_back(1);
                else row.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
            res.push_back(row);
        }
        return res;
    }
};
