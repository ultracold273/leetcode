/**
 * LeetCode Q153 - Find Minimum in Rotated Sorted Array
 * Suppose an array sorted in ascending order is rotated at some 
 * pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 */

/* Binary Search, O(logN) */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int st = 0;
		int ed = nums.size() - 1;
		while(ed - st > 1) {
			if (nums[st] < nums[ed]) return nums[st];
			int mid = (ed + st) / 2;
			if (nums[mid] > nums[st]) {
				st = mid;
			}else{
				ed = mid;
			}
		}
		if (ed - st == 1) return min(nums[ed], nums[st]);
		else return nums[ed];
	}
};
