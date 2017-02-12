/**
 * LeetCode Q137 - Single Number II
 * Given an array of integers, every element appears three times except 
 * for one, which appears exactly once. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. 
 * Could you implement it without using extra memory?
 *
 */

#include <vector>
using namespace std;

/**
 * This series of questions can be solved by finite machines
 * using boolean logic.
 * Suppose we want to find out a number that appeared k times while
 * other appeared p times. We can define a finite machine that transfer
 * back to 0 after p times while transfer to 1 after k times.
 * Use this as a example:
 * bit1 bit0 incoming nextbit1 nextbit0
 *  0    0      0        0        0
 *  0    1      0        0        1
 *  1    0      0        1        0
 *  0    0      1        0        1
 *  0    1      1        1        0
 *  1    0      1        0        0
 *
 *  so bit0 = ~bit1 & (bit0 ^ incoming)
 *  bit1 = ~nxtbit0 & (bit1 ^ incoming)
 */

class Solution {
public:
	int singleNumber(vector<int> &nums) {
		int bit0 = 0;
		int bit1 = 0;
		for (auto num : nums) {
			bit0 = (bit0 ^ num) & (~bit1);
			bit1 = (bit1 ^ num) & (~bit0);
		}
		return bit0;
	}
};
