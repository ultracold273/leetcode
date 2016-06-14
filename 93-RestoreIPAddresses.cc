/**
 * Leetcode Q93 - Restore IP Addresses
 * Given a string containing only digits, restore it by returning 
 * all possible
 * valid IP address combinations
 *
 * For example:
 * Given "25525511135",
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */
 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		switch(s.size()) {
			case 1: return true;
			case 2: return (s >= "10" && s <= "99")? true: false;
			case 3: return (s >= "100" && s <= "255")? true: false;
			default: return false;
		}
	}

	int IpAddrSplit(string s, unsigned int parts, vector<string>& container) {
		if (s.size() < parts || s.size() > 3 * parts) return 0;
		if (parts == 1) {
			if (isValid(s)) {container.push_back(s);return 1;}
			else return 0;
		}else {
			int flagSuccessSplit = 0;
			for (int i = 1;i <= 3;i++) {
				if (s.size() < i) break;
				string startS = s.substr(0, i);
				string leftS = s.substr(i, s.size() - i);
				vector<string> res;
				if (isValid(startS) && 1 == IpAddrSplit(leftS, parts - 1, res)) {
					flagSuccessSplit = 1;
					for (int idx = 0;idx < res.size();idx++) {
						container.push_back(startS + "." + res[idx]);
					}
				}
			}
			return flagSuccessSplit;
		}
	}

    vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		IpAddrSplit(s, 4, res);
		return res;
    }
};

int main(int argc, char * argv[]) {
	string s = "0000";
	Solution * sol = new Solution();
	vector<string> res = sol->restoreIpAddresses(s);
	for (int i = 0;i < res.size();i++) {
		cout << res[i] << endl;
	}
}
