/**
 * Given an array of non-negative integers, you are initially 
 * positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length 
 * at that position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * For example:
 * Given array A = [2,3,1,1,4]
 *
 * The minimum number of jumps to reach the last index is 2. 
 * (Jump 1 step from index 0 to 1, then 3 steps to the last index.) 
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int jump(vector<int> &nums) {
		int farestPos = 0;
		int prevFarestPos = 0;
		int step = 0;
		bool stepIncrease = false;
		int lastPos = nums.size() - 1;
		for (int i = 0;i <= lastPos;i++) {
			if (stepIncrease) {
				step++;
				stepIncrease = false;
			}
			if (i == 0) {
				farestPos = prevFarestPos = nums[i];
				stepIncrease = true;
				continue;
			}
			if (i + nums[i] > farestPos) {
				farestPos = i + nums[i];
			}
			if (i == prevFarestPos) {
				stepIncrease = true;
				prevFarestPos = farestPos;
			}
		}
		return step;
	}

	int jump_old(vector<int> &nums) {
		vector<int> minimunJump (nums.size(), 0);
		int lastPos = nums.size() - 1;
		for(int i = lastPos - 1;i >= 0;i--) {
			if(lastPos - i <= nums[i]) {
				minimunJump[i] = 1;
			}else{
				minimunJump[i] = min(minimunJump, i + 1, i + nums[i]) + 1;
			}
		}
		return minimunJump[0];
	}
	
	int min(vector<int> &nums, int stPos, int edPos) {
		int minimun = nums[stPos];
		for (int i = edPos;i > stPos;i--) {
			if (nums[i] < minimun) {
				minimun = nums[i];
			}
		}
		return minimun;
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	int a[] = {2, 3, 1, 1, 4};
	vector<int> av (a, a + sizeof(a)/sizeof(int));
	cout << sol->jump(av) << endl;
	
	int b[] = {1, 1, 1, 1};
	vector<int> bv (b, b + sizeof(b)/sizeof(int));
	cout << sol->jump(bv) << endl;
}
