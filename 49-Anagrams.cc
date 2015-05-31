/**
 * Given an array of strings, return all groups of strings
 * that are anagrams.
 *
 * Note: All inputs will be in lower-case.
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	vector<string> anagrams(vector<string>& strs) {
		vector<string> res;
		map<string, string> mp;
		for (int i = 0;i < (int) strs.size();i++) {
			string test = strs[i];
			sort(test.begin(), test.end());
			// Find whether already in the dict
			if (mp.find(test) == mp.end()) {
				// Not in the dict, insert it
				mp.insert(pair<string, string> (test, 'N' + strs[i]));
			}else {
				// If in the dict, anagram found
				// Judge whether we need to insert the first found elem
				if (!mp[test].empty() && mp[test].front() == 'N') {
					// the first found elem is not inserted
					mp[test] = mp[test].substr(1);
					res.push_back(mp[test]);
				}
				// insert the found elem currently
				res.push_back(strs[i]);
			}
		}
		return res;
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
//	cout << sol->anagrams() << endl;
}
