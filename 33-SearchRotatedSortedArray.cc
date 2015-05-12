/**
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * You are given a target value to search. if found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int search(vector<int>& nums, int target) {
			int right = nums.size() - 1;
			int left = 0;
			while(right >= left) {
//				cout << right << ' ' << left << endl;
				int midVal = nums[(right + left)/2];
				int leftVal = nums[left];
				int rightVal = nums[right];
				if (midVal == target) return (right + left) / 2;
				if (leftVal == target) return left;
				if (rightVal == target) return right;
				else {
					if (target > midVal) {
						if (rightVal > midVal && target > rightVal) {
							if (leftVal > rightVal)
								right = (right + left)/2 - 1;
							else
								return -1;
						}else{
							left = (right + left)/2 + 1;
						}
					}else{
						if (leftVal < midVal && target < leftVal) {
							if (rightVal < leftVal)
								left = (right + left)/2 + 1;
							else
								return -1;
						}else{
							right = (right + left)/2 - 1;
						}
					}
				}
			}
			return -1;
		}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	int a[7] = {4, 5, 6, 7, 0, 1, 2};
	vector<int> num (a, a + sizeof(a)/sizeof(int));
	cout << sol->search(num, 0) << endl;
	cout << sol->search(num, 1) << endl;
	cout << sol->search(num, 2) << endl;
	cout << sol->search(num, 3) << endl;
	cout << sol->search(num, 4) << endl;
	cout << sol->search(num, 5) << endl;
	cout << sol->search(num, 6) << endl;
	cout << sol->search(num, 7) << endl;
	cout << sol->search(num, 8) << endl;

	return 0;
}
