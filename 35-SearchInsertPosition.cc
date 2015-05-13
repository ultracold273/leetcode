/**
 * Given a sorted array and target value, return the index if the target
 * is found. If not, return the index where it would be if it were
 * inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 *
 * [1, 3, 5, 6], 5 --> 2
 *
 * [1, 3, 5, 6], 2 --> 1
 *
 * [1, 3, 5, 6], 7 --> 4
 *
 * [1, 3, 5, 6], 0 --> 0
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int searchInsert(vector<int> & nums, int target) {
			int left = 0;
			int right = nums.size() - 1;
			while(right > left + 1) {
				int mid = (right + left)/2;
				if (nums[mid] == target) {
					return mid;
				}else if(nums[mid] > target) {
					right = mid;
				}else{
					left = mid;
				}
			}
			if (nums[left] >= target) {
				return left;
			}
			if (nums[right] == target) {
				return right;
			}else if (nums[right] < target) {
				return right + 1;
			}else{
				return right;
			}
		}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	int a[] = {1, 3, 5, 6};
	vector<int> nums (a, a + sizeof(a)/sizeof(int));
	cout << sol->searchInsert(nums, 5) << endl;
	cout << sol->searchInsert(nums, 2) << endl;
	cout << sol->searchInsert(nums, 7) << endl;
	cout << sol->searchInsert(nums, 0) << endl;
	return 0;
}
