/**
 * LeetCode Q97 - Interleaving String
 * Given s1, s2, s3, find whether s3 is formed by the interleaving 
 * of s1 and s2.
 *
 * For example,
 * Given:
 * s1 = "aabcc",
 * s2 = "dbbca",
 *
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s3.size() != s1.size() + s2.size()) return false;
		return true;
	}
};
