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

		// Dict storing the position of every char
		unordered_map<char, vector<int> > dictSpos;
		for (int i = 0;i < (int) s.size();i++) {
			if (dictTNum.find(s[i]) != dictTNum.end()) {
				if (dictTNum[s[i]] != 0) {
					if (dictSpos.find(s[i]) != dictSpos.end()) {
						dictSpos[s[i]].push_back(i);
					}else{
						dictSpos[s[i]] = vector<int>(1, i);
					}
				}else{
					// the number shall be in multiple times
					dictSpos[s[i]].erase(dictSpos[s[i]].begin());
					dictSpos[s[i]].push_back(i);
				}
			}
		}

		unordered_map<char, int>::iterator it;
		for (it = dictTNum.begin();it != dictTNum.end();it++) {
			if (it->second != 0) return "";
		}
		unordered_map<char, vector<int> >::iterator it_v;
		int st = -1;
		int ed = s.size();
		for (it_v = dictSpos.begin();it_v != dictSpos.end();it++) {
			vector<int> temp = it_v->second;
			if ((*(temp.begin())) >
		}
	}
}
