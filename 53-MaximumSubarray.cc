/**
 * Find the contiguous subarray within an array (containing at 
 * least one number) which has the largest sum.
 *
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 *
 * More practice:
 *
 * If you have figured out the O(n) solution, try coding another 
 * solution using the divide and conquer approach, which is more subtle.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

#define INT_MIN (-2147483647 - 1)

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int rvSum = INT_MIN;
		int sum = 0;
		for (int i = 0;i < (int) nums.size();i++) {
			sum += nums[i];
			if (rvSum < sum) rvSum = sum;
			if (sum < 0) sum = 0;
		}
		return rvSum;
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	vector<int> array (a, a + sizeof(a)/sizeof(int));
	cout << sol->maxSubArray(array) << endl;
	return 0;
}
