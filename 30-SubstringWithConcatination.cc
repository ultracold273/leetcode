/**
 *
 * You are given a string, S, and a list of words, L, that are all of the same length. 
 * Find all starting indices of substring(s) in S that is a concatenation of each 
 * word in L exactly once and without any intervening characters.

 * For example, given:
 * S: "barfoothefoobarman"
 * L: ["foo", "bar"]

 * You should return the indices: [0,9].
 * (order does not matter).
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
		map<string, int> m;
		// Hash every element in L
		int vecSize = L.size();
		for(int i = 0;i < vecSize;i++) {
			if(m.find(L[i]) != m.end()) {
				m[L[i]] += 1;
			}else{
				m[L[i]] = 1;
			}
		}
		int wordLength = L[0].size();
		vector<int> res;
		int stringLen = S.size();
		for (int i = 0;i <= stringLen - wordLength*vecSize;i++) {
			bool find = true;
			map<string, int> mTemp;
			for (int j = 0;j < vecSize;j++) {
				string one = S.substr(i + j*wordLength, wordLength);
				if (m.find(one) == m.end()) {
					find = false;
					break;
				}else{
					if(mTemp.find(one) != mTemp.end()) {
						mTemp[one] += 1;
						if (mTemp[one] > m[one]) {
							find = false;
							break;
						}
					}else{
						mTemp[one] = 1;
					}
				}
			}
			if (find) {
				res.push_back(i);
			}
		}
		return res;
    }
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
	vector<string> L;
	L.push_back(string("fooo"));
	L.push_back(string("barr"));
	L.push_back(string("wing"));
	L.push_back(string("ding"));
	L.push_back(string("wing"));
	vector<int> res = sol->findSubstring(s, L);
	for(int i = 0;i < (int) res.size();i++) {
		cout << " " << res[i];
	}
	cout << endl;
	return 0;
}
