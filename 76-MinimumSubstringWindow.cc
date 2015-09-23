/*
 * Given a string S and a string T, find the minimum window 
 * in S which will contain all the characters in T in 
 * complexity O(n).
 * 
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 * 
 * Note:
 * If there is no such window in S that covers all characters in T, 
 * return the emtpy string "".
 *
 * If there are multiple such windows, you are guaranteed that 
 * there will always be only one unique minimum window in S.
 */

 /* keep a dictionary of t
  * keep a queue of anchor index stores the char that matches with t in s
  * if an extra char is matched and it is the same with first anchor char
  * pop to next anchor index
  */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		// Pre-processing
		unordered_map<char, int> dictTNum;
		for (int i = 0;i < (int) t.size();i++) {
			if (dictTNum.find(t[i]) != dictTNum.end()) {
				dictTNum[t[i]] += 1;
			}else {
				dictTNum[t[i]] = 1;
			}
		}

		int start = 0, end = 0;
		while(end < (int) s.size()) {
			if ()
		}
		return "";
	}
}
