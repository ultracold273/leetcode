/**
 * LeetCode Q131 - Palindrome Partioning
 *
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * 
 * Return all possible palindrome partitioning of s.
 * 
 * For example, given s = "aab",
 * Return
 * 
 * [
 *   ["aa","b"],
 *   ["a","a","b"]
 * ]
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.size() == 0) return res;
    }
};
