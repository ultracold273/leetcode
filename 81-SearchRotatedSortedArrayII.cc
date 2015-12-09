/**
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 *
 * Would this affect the run-time complexity? How and why?
 *
 * Write a function to determine if a given target is in the array.
 */

#include <iostream>
#include <vector>
using namespace std;

/* Still Binary search */
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.size() == 0) return false;
		if (nums.size() == 1) {
			if (nums[0] == target) return true;
			else return false;
		}
		if (nums.size() == 2) {
			if (nums[0] == target || nums[1] == target) return true;
			else return false;
		}
		int last = nums[nums.size() - 1];
		int first = nums[0];
		int midPos = nums.size()/2;
		int mid = nums[midPos];

		if (last > first) {
			if (mid == target) return true;
			else if (mid > target) {
				vector<int> temp(nums.begin(), nums.begin() + midPos);
				return search(temp, target);
			}else{
				vector<int> temp(nums.begin() + midPos + 1, nums.end());
				return search(temp, target);
			}
		}else if (last == mid && last == first) {
		    vector<int> temp1(nums.begin(), nums.begin() + midPos);
			vector<int> temp2(nums.begin() + midPos + 1, nums.end());
		    return search(temp1, target) || search(temp2, target);
		}else {
			if (mid == target) return true;
			else if (mid > first) {
				if (target >= first && target < mid) {
					vector<int> temp(nums.begin(), nums.begin() + midPos);
					return search(temp, target);
				}else{
					vector<int> temp(nums.begin() + midPos + 1, nums.end());
					return search(temp, target);
				}
			}else if (mid == first){
					vector<int> temp(nums.begin() + midPos + 1, nums.end());
					return search(temp, target);
			}else if (mid == last) {
				vector<int> temp(nums.begin(), nums.begin() + midPos);
				return search(temp, target);
			}else {
				if (target > mid && target <= last) {
					vector<int> temp(nums.begin() + midPos + 1, nums.end());
					return search(temp, target);
				}else {
					vector<int> temp(nums.begin(), nums.begin() + midPos);
					return search(temp, target);
				}
			}
		}
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	int array[] = {5, 6, 7, 1, 2, 3, 4, 5};
	vector<int> nums(array, array + sizeof(array) / sizeof(int));
	cout << sol->search(nums, 0) << endl;
	cout << sol->search(nums, 1) << endl;
	cout << sol->search(nums, 2) << endl;
	cout << sol->search(nums, 3) << endl;
	cout << sol->search(nums, 4) << endl;
	cout << sol->search(nums, 5) << endl;
}
