/**
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. 
 * In how many distinct ways can you climb to the top? 
 *
 * Dynamic Programming
 */

class Solution {
public:
	int climbStairs(int n) {
		if (n == 1) return 1;
		if (n == 2) return 2;
		int res1 = 1;
		int res2 = 2;
		int res;
		for(int i = 3;i <= n;i++) {
			res = res1 + res2;
			res1 = res2;
			res2 = res;
		}
		return res;
	}
};
