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
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool isInterleave_rec(string s1, string s2, string s3) {
		if (s3.size() != s1.size() + s2.size()) return false;
		if (s1 == "") return s2 == s3;
		if (s2 == "") return s1 == s3;
		if (s3[0] != s1[0] && s3[0] != s2[0]) {
			return false;
		}else{
			if (s3[0] == s1[0] && s3[0] == s2[0]) {
				return isInterleave_rec(s1.substr(1, s1.size() - 1), s2, s3.substr(1, s3.size() - 1)) |
					isInterleave_rec(s1, s2.substr(1, s2.size() - 1), s3.substr(1, s3.size() - 1));
			}else if (s3[0] == s1[0]) {
				return isInterleave_rec(s1.substr(1, s1.size() - 1), s2, s3.substr(1, s3.size() - 1));
			}else{
				return isInterleave_rec(s1, s2.substr(1, s2.size() - 1), s3.substr(1, s3.size() - 1));
			}
		}
	}
/**
 * Use Dynamic programming would save a lot on stack space?
 * Suppose we have s1 = "abc", s2 = "def", s3 = "abdcef"
 *   a b c V       a b c V
 * d             d T T T
 * e             e     T T
 * f             f       T
 * V       T     V       T
 *
 * Suppose we have s1 = "abf", s2 = "def", s3 = "abdfef"
 *   a b f V       a b f V
 * d             d T T T
 * e             e     T T
 * f             f     F T
 * V       T     V   F T T
 *
 */
    bool isInterleave(string s1, string s2, string s3) {
		int size1 = s1.size(), size2 = s2.size(), size3 = s3.size();
        if (size3 != size1 + size2) return false;
		vector<vector<bool> > dpMatrix(size1 + 1, vector<bool>(size2 + 1, false));
		dpMatrix[size1][size2] = true;
		for (int i = size2 - 1;i >= 0;i--) {
			dpMatrix[size1][i] = (!dpMatrix[size1][i+1])?false:s2[i] == s3[size1 + i];
		}
		for (int i = size1 - 1;i >= 0;i--) {
			dpMatrix[i][size2] = (!dpMatrix[i+1][size2])?false:s1[i] == s3[size2 + i];
		}
		for (int i = size1 - 1;i >=0;i--) {
			for(int j = size2 -1;j >= 0;j--) {
				dpMatrix[i][j] = (s1[i] == s3[i+j] && dpMatrix[i+1][j]) || (s2[j] == s3[i+j] && dpMatrix[i][j+1]);
			}
		}
		return dpMatrix[0][0];
    }
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3_true = "aadbbcbcac";
	string s3_false = "aadbbbaccc";
	cout << sol->isInterleave(s1, s2, s3_true) << endl;
	cout << sol->isInterleave(s1, s2, s3_false) << endl;
} 

