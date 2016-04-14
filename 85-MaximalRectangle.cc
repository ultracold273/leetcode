/**
 * Leetcode 85 - Maximal Rectangle
 * Given a 2D binary matrix filled with 0's and 1's, 
 * find the largest rectangle containing all ones and return its area.
 *
 */
 
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int res = 0;
        stack<int> s;
        heights.push_back(0);
        
        for (int i = 0;i < heights.size();i++) {
            if (s.empty() || heights[i] >= heights[s.top()]) {
                int tp = s.top();
                int h = heights[tp];
                s.pop();
                
                int tmp = h * (s.empty() ? i : i - s.top() - 1);
                res = max(res, tmp);
            }
            s.push(i);
        }
        return res;
    }
    /**
     * Using the largest Rectangle method above
     * first construct a vector containing all consecutive 1s in the col
     * then calculate the largest rectangle on the current row
     */
    int maximalRectangle(vector<vector<char> >& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        int max = 0;
        vector<int> vecLine(col, 0);
        for (int i = 0;i < col;i++) {
            vecLine[i] = matrix[0][i] - '0';
        }
        max = largestRectangleArea(vecLine);
        for(int j = 1;j < row;j++) {
            for (int i = 0;i < col;i++) {
                if (matrix[j][i] == '1') {
                    vecLine[i] += 1;
                }else{
                    vecLine[i] = 0;
                }
            }
            int temp = largestRectangleArea(vecLine);
            max = (max > temp) ? max : temp;
        }
        return max;
    }    
};