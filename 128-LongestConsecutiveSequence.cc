/**
 * LeetCode Q128 - Longest Consecutive Sequence
 *
 * Given an unsorted array of integers, find the length of the longest 
 * consecutive elements sequence.
 *
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. 
 * Return its length: 4.
 *
 * Your algorithm should run in O(n) complexity. 
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public: 
    int longestConsecutive(vector<int>& nums) { 
        int maxLength = 0;
        unordered_map<int, int> hashMap;
        for (auto it = nums.begin();it != nums.end();++it) {
            if (hashMap.find(*it) == hashMap.end()) {
                if (hashMap.find(*it - 1) == hashMap.end()) {
                    if (hashMap.find(*it + 1) == hashMap.end()) {
                        // Not Consecutive
                        hashMap[*it] = *it;
                        if (1 > maxLength) maxLength = 1;
                    }else{
                        // Right Consecutive
                        int rangeEnd = hashMap[*it + 1];
                        hashMap[rangeEnd] = *it;
                        hashMap[*it] = rangeEnd;
                        int range = rangeEnd - *it + 1;
                        if (range > maxLength) maxLength = range;
                    }
                }else{
                    if (hashMap.find(*it + 1) == hashMap.end()) {
                        // Left Consecutive
                        int rangeEnd = hashMap[*it - 1];
                        hashMap[rangeEnd] = *it;
                        hashMap[*it] = rangeEnd;
                        int range = *it - rangeEnd + 1;
                        if (range > maxLength) maxLength = range;
                    }else{
                        // Connected
                        int rangeLow = hashMap[*it - 1];
                        int rangeHigh = hashMap[*it + 1];
                        hashMap[rangeLow] = rangeHigh;
                        hashMap[rangeHigh] = rangeLow;
                        hashMap[*it] = rangeHigh;
                        int range = rangeHigh - rangeLow + 1;
                        if (range > maxLength) maxLength = range;
                    }
                }
            }
        }
        return maxLength;
    } 
};

int main() {
    Solution * sol = new Solution();
    //int a[] = {100, 4, 200, 1, 3, 2};
    int a[] = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    vector<int> v(a, a + sizeof(a)/sizeof(int));
    cout << sol->longestConsecutive(v) << endl;
    return 0;
}
