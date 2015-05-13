/**
 * Given a sorted array of integers, find the starting and ending position
 * of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * For example, 
 * Given [5, 7, 7, 8, 8, 10] and the target value 8,
 * return [3, 4].
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		vector<int> searchRange(vector<int>& nums, int target) {
			int right = nums.size() - 1;
			int left = 0;
			bool flag = false;
			vector<int> res (2, -1);
			while(right > left + 1) {
				if (nums[(right + left)/2] >= target) {
					right = (right + left)/2;
				}else {
					left = (right + left)/2;
				}
			}
			if (left == 0 && nums[left] == target) {
				res[0] = 0;
				flag = true;
			}
			else if (nums[right] == target) {
				res[0] = right;
				flag = true;
			}
			if (flag) {
				right = nums.size() - 1;
				left = res[0];
				while(right > left + 1) {
					if (nums[(right + left)/2] <= target) {
						left = (right + left)/2;
					}else{
						right = (right + left)/2;
					}
				}
				if(right == (int) nums.size() - 1 && nums[right] == target) {
					res[1] = right;
				}else if (nums[left] == target) {
					res[1] = left;
				}
			}
			return res;
		}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	int a[] = {1, 1, 3, 7, 7, 8, 8, 8, 8};
	vector<int> v (a, a + sizeof(a)/sizeof(int));
	vector<int> t = sol->searchRange(v, 1);
	for (int i = 0;i < (int) t.size();i++)
		cout << t[i] << ' ';
	cout << endl;

	t = sol->searchRange(v, 3);
	for (int i = 0;i < (int) t.size();i++)
		cout << t[i] << ' ';
	cout << endl;

	t = sol->searchRange(v, 7);
	for (int i = 0;i < (int) t.size();i++)
		cout << t[i] << ' ';
	cout << endl;

	t = sol->searchRange(v, 8);
	for (int i = 0;i < (int) t.size();i++)
		cout << t[i] << ' ';
	cout << endl;
	return 0;
}
