/**
 * LeetCode Q152 - Maximum Product Subarray
 * Find the contiguous subarray within an array (containing at least one 
 * number) which has the largest product.
 *
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 */

/**
 * Interesting problem. Can be solved by Dynamic programming
 * What if the nums are in float type, both positive and negetive
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int gMin, gMax;
        if (nums.size() == 0) return 0;
        gMin = gMax = nums[0];
        int aMin, aMax;
        aMin = aMax = nums[0];
        for (size_t i = 1;i < nums.size();i++) {
			int aMax_t, aMin_t;
            aMax_t = max(max(aMax * nums[i], aMin * nums[i]), nums[i]);
            aMin_t = min(min(aMin * nums[i], aMax * nums[i]), nums[i]);
			aMax = aMax_t;aMin = aMin_t;
            if (aMax > gMax) gMax = aMax;
            if (aMin < gMin) gMin = aMin;
        }
        return gMax;
    }
};

int main() {
	vector<int> a(3, 0);
	a[0] = -4;a[1] = -3, a[2] = -2;
	Solution * sol = new Solution();
	cout << sol->maxProduct(a) << endl;
	delete sol;
}
