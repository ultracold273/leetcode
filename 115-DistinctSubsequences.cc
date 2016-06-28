/**
 * LeetCode Q115 - Distinct Subsequences
 * Given a string S and a string T, count the number of distinct 
 * subsequences of T in S.
 *
 * A subsequence of a string is a new string which is formed from the 
 * original string by deleting some (can be none) of the characters 
 * without disturbing the relative positions of the remaining characters. 
 * (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 *
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 *
 * Return 3.
 *
 */

/**
 * This problem can be done in a dynamic programming manner
 * The calculation procedure is shown in the below table
 * Each cell (i, j) represents the number of distinct subsequence 
 * of T[0:j] in S[0:i]
 * if T[j] != S[i] meaning S[i] must be deleted in order to get T[0:j]
 * cell(i, j) = cell(i - 1, j)
 * if T[j] == S[i]
 * cell(i, j) = cell(i - 1, j - 1) + cell(i - 1, j)
 * |S\T|r|a|b|b|i|t|
 * | r |1|X|X|X|X|X|
 * | a |1|1|X|X|X|X|
 * | b |1|1|1|X|X|X|
 * | b |1|1|2|1|X|X|
 * | b |1|1|3|3|X|X|
 * | i |1|1|3|3|3|X|
 * | t |1|1|3|3|3|3|
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
        int size1 = s.size();
        int size2 = t.size();
        if (size1 < size2) return 0;
        vector<vector<int> > mat(size1, vector<int>(size2, 0));
        for(int i = 0;i < size1;i++) {
            for(int j = 0;j <= i && j < size2;j++) {
                if (s[i] != t[j]) {
                    mat[i][j] = (i==0)?0:mat[i-1][j];
                }else{
                    mat[i][j] = ((i==0)?0:mat[i-1][j]) + ((j==0)?1:mat[i-1][j-1]);
                }
//                cout << i << " " << j << " " << mat[i][j] << endl;
            }
        }
		return mat[size1-1][size2-1];
	}
};

int main() {
    Solution * sol = new Solution();
    cout << sol->numDistinct("rabbbit", "rabbit") << endl;
}
