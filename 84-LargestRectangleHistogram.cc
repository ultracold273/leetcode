/**
 * Given n non-negative integers representing the histogram's bar 
 * height where the width of each bar is 1, find the area of largest 
 * rectangle in the histogram.
 *
 *
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 *
 *
 * The largest rectangle is shown in the shaded area, 
 * which has area = 10 unit.
 *
 * For example,
 * Given height = [2,1,5,6,2,3],
 * return 10. 
 *
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 * Invariant: Keep the index in stack whose heights is in 
 * increasing order.
 */

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		stack<int> s;
		int res = 0;
		heights.push_back(0);

		for(int i = 0;i < heights.size();i++) {
			if (s.empty() || heights[i] >= heights[s.top()]) {
				s.push(i);
			}else{
				while(!s.empty() && heights[i] < heights[s.top()]) {
					int h = heights[s.top()];
					s.pop();

					int tmp = h * (s.empty()?i:i - s.top() + 1);
					res = max(res, tmp);
				}
				s.push(i);
			}
		}
		return res;
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	int height[] = {2, 1, 5, 6, 2, 3};
	vector<int> vheight(height, height + sizeof(height)/sizeof(int));
	cout << sol->largestRectangleArea(vheight) << endl;
	return 0;
}
