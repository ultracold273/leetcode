/**
 * Given an unsorted integer array, find the first missing positive
 * integer:
 *
 * For example,
 * Given [1, 2, 0] return 3,
 * and [3, 4, -1, 1] return 2.
 *
 * Your algorithm should run in O(n) time and use constant space.
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 *  Very clever Idea!!
 */
 
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int numSize = nums.size();
		for(int i = 0;i < numSize;i++) {
			int target = nums[i];
			while(target > 0 && target <= numSize && target != nums[target-1]) {
				int newTarget = nums[target-1];
				nums[target-1] = target;
				target = newTarget;
			}
		}

		for (int i = 0; i < numSize; ++i)
		{
			if (nums[i] != i + 1)
				return i + 1;
		}
		
		return numSize + 1;
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	int a[] = {1, 2, 0};
	vector<int> av (a, a + sizeof(a)/sizeof(int));
	cout << sol->firstMissingPositive(av) << endl;

	int b[] = {3, 4, -1, 1};
	vector<int> bv (b, b + sizeof(b)/sizeof(int));
	cout << sol->firstMissingPositive(bv) << endl;

	int c[] = {3, 4, 5, 1, 2};
	vector<int> cv (c, c + sizeof(c)/sizeof(int));
	cout << sol->firstMissingPositive(cv) << endl;
	return 0;
}
