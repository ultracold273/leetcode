/**
 * LeetCode Q136 - Single Number
 * Given an array of integers, every element appears twice except for 
 * one. 
 * Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. 
 * Could you implement it without using extra memory? 
 */

#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singular = 0;
        for (int i = 0;i < (int)nums.size();i++) {
            singular ^= nums[i];
        }
        return singular;
    }
};
