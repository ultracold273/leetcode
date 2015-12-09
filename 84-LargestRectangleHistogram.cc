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

class Solution {
public:
	int largestRectangleArea(vector<int>& height) {
		return 0;
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	int height[] = {2, 1, 5, 6, 2, 3};
	vector<int> vheight(height, height + sizeof(height)/sizeof(int));
	cout << sol->largestRectangleArea(vheight) << endl;
	return 0;
}
