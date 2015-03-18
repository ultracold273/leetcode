/**
 * Write a function to find the longest common prefix
 * string amongst an array of strings.
 */

#include <iostream>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		string res = "";
		if (strs.size() == 0) return res;
		res = strs[0];
		for(int i = 1;i < strs.size();i++) {
			int maxCompareSize = (res.size() < strs[i].size())?res.size():strs[i].size();
			int j;
			for (j = 0;j < maxCompareSize;j++) {
				if(res[j] != strs[i][j]) break;
			}
			res = res.substr(0, j);
		}
		return res;
	}
};

int main(int argc, char * argv[]) {
	return 0;
}
