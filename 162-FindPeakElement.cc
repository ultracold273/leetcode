/**
 * LeetCode Q162 - Find Peak Element
 * A peak element is an element that is greater than its neighbors.
 *
 * Given an input array where num[i] ≠ num[i+1], find a peak element 
 * and return its index.
 *
 * The array may contain multiple peaks, in that case return the index 
 * to any one of the peaks is fine.
 *
 * You may imagine that num[-1] = num[n] = -∞.
 *
 * For example, in array [1, 2, 3, 1], 3 is a peak element and your 
 * function should return the index number 2.
 *
 * Note:
 * Your solution should be in logarithmic complexity.
 */

#include <vector>
using namespace std;

class Solution {
public:
    int gradientFinder(vector<int>&nums, int idx) {
        /* 0 -- Peak, 1 -- Mono Increase, 2 -- Mono Decrease, 3 -- Valley */
        if (idx == 0) {
            return 1;
        }else if (idx == nums.size() - 1) {
            return 2;
        }else {
            bool before = (nums[idx] > nums[idx - 1]);
            bool after = (nums[idx] > nums[idx + 1]);
            if (before & after) return 0;
            else if (before & !after) return 1;
            else if (!before & after) return 2;
            else return 3;
        }
    }
    
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return 0;
        else {
            if (nums[0] > nums[1]) return 0;
            if (nums[nums.size() - 1] > nums[nums.size()-2]) return nums.size() - 1;
            int st = 0;int ed = nums.size() - 1;
            while(st < ed - 1) {
                int mid = (st + ed) / 2;
                int midGrad = gradientFinder(nums, mid);
                if (midGrad == 0) return mid;
                else if (midGrad == 1) st = mid;
                else ed = mid;
            }
            if (st == ed) return st;
            else if (nums[st] > nums[ed]) return st;
            else return ed;
        }
    }
};
