/**
 * Leetcode 87 - Scramble String
 * Given a string s1, we may represent it as a binary tree by partitioning it 
 * to two non-empty substrings recursively.
 * 
 * Below is one possible representation of s1 = "great":
 * 
 *     great
 *    /    \
 *   gr    eat
 *  / \    /  \
 * g   r  e   at
 *            / \
 *           a   t
 * To scramble the string, we may choose any non-leaf node and swap 
 * its two children.
 * 
 * For example, if we choose the node "gr" and swap its two children,
 * it produces a scrambled string "rgeat".
 *
 *     rgeat
 *    /    \
 *   rg    eat
 *  / \    /  \
 * r   g  e   at
 *            / \
 *           a   t
 * We say that "rgeat" is a scrambled string of "great".
 *
 * Similarly, if we continue to swap the children of nodes "eat" and "at", 
 * it produces a scrambled string "rgtae".
 *
 *     rgtae
 *    /    \
 *   rg    tae
 *  / \    /  \
 * r   g  ta  e
 *        / \
 *       t   a
 * We say that "rgtae" is a scrambled string of "great".
 * 
 * Given two strings s1 and s2 of the same length, determine if s2 
 * is a scrambled string of s1.
 */
 
 #include <iostream>
 #include <algorithm>
 using namespace std;
 
 class Solution {
 public:
     bool isScramble(string s1, string s2) {
		string s1_srt = s1;
		string s2_srt = s2;
		sort(s1_srt.begin(), s1_srt.end());
		sort(s2_srt.begin(), s2_srt.end());
		int str_len = s1.size();
		if (s1_srt != s2_srt) {
			return false;
		}else if (str_len == 1) {
			return s1 == s2;
		}else{
			for (int i = 1; i < str_len; i++) {
				// Check the same sequence
				if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, str_len - i), s2.substr(i, str_len - i))) return true;
				// Check the opposite
				if (isScramble(s1.substr(0, i), s2.substr(str_len - i, i)) && isScramble(s1.substr(i, str_len - i), s2.substr(0, str_len - i))) return true;
			}
			return false;
		}
	}
 };
 
 int main() {
     string s1 = "great";
     string s2 = "rgeat";
 }