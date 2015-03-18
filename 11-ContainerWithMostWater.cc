/**
 * LeetCode Question 11 - Container With Most Water
 * Given n non-negative integers a1, a2, ..., an, where each represents
 * a points at coordinate (i, a). n vertical lines are drawn such that 
 * the two endpoints of line i is at (i, ai) and (i, 0). Find two lines
 * which together with x-axis forms a container, such that the container
 * contains the most water.
 */

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
	public:
		int maxArea(vector<int> &height) {
			int max = 0;
			int left = 0;
			int right = height.size() - 1;
			int tempMax;

			max = (right - left) * ((height[right] > height[left])?height[left]:height[right]);
			while(left < right) {
				tempMax = (right - left) * ((height[right] > height[left])?height[left]:height[right]);
				max = (max > tempMax)?max:tempMax;
				(height[left] < height[right])?left++:right--;
			}
			return max;
		}
};

int main() {
	Solution * sol = new Solution();
	return 1;
}
