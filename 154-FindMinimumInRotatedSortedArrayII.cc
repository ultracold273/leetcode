/**
 * LeetCode Q154 - Find Minimum in Rotated Sorted Array II
 *
 * Suppose an array sorted in ascending order is rotated at some pivot 
 * unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.
 *
 * **The array may contain duplicates.**
 */

#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0;
        int ed = nums.size() - 1;
        while(ed - st > 1) {
            int mid = (ed + st) / 2;
            if (nums[ed] > nums[st]) return nums[st];
            else if (nums[ed] == nums[st]) {
                if (nums[mid] == nums[st]) {
                    while(st < mid - 1 && nums[++st] == nums[mid]);
                    if (nums[st] != nums[mid]) return min(nums[st], nums[mid]);
                    else st = mid;
                }else if (nums[mid] > nums[st]) {
                    st = mid;
                }else{
                    ed = mid;
                }
            }else {
                if (nums[mid] >= nums[st]) {
                    st = mid;
                }else {
                    ed = mid;
                }
            }
        }
        if (ed == st) return nums[ed];
        else return min(nums[st], nums[ed]);
    }
};