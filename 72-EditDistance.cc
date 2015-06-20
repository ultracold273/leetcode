/**
 * Given two words word1 and word2, find the minimum number of steps 
 * required to convert word1 to word2. (each operation is counted as 
 * 1 step.)
 *
 * You have the following 3 operations permitted on a word:
 *
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Construct a table that showing the edit ditance
 * woods --> waodous
 *      w a o d o u s
 *   w  0 1 2 3 4 5 6
 *   o  1 1 1 2 3 4 5
 *   o  2 2 1 2 2 3 4
 *   d  3 3 2 1 2 3 4
 *   s  4 4 3 2 2 3 3
 * Final result is 3
 * When dealing with every cell, if word1[i] == word2[j], cell[i][j] = cell[i-1][j-1]
 * else cell[i][j] = min(cell[i-1][j], cell[i][j-1], cell[i-1[j-1])
 */
class Solution {
public:
	int min(int a, int b, int c){
		if (a <= b && a <= c) {
			return a;
		}else if (b <= c) {
			return b;
		}else{
			return c;
		}
	}

	int minDistance(string word1, string word2) {
		int word1Length = word1.size();
		int word2Length = word2.size();
		vector<vector<int> > matrix(word1Length + 1, vector<int>(word2Length + 1, 0));
		// Initialize dummy 
		for (int i = 0;i <= word1Length;i++) matrix[i][0] = i;
		for (int j = 0;j <= word2Length;j++) matrix[0][j] = j;
		for(int i = 1;i <= word1Length;i++) {
			for(int j = 1;j <= word2Length;j++) {
				if (word1[i-1] == word2[j-1]) {
					matrix[i][j] = matrix[i - 1][j - 1];
				}else{
					matrix[i][j] = min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]) + 1;
				}
			}
		}
		return matrix[word1Length][word2Length];
	}
};

int main(int argc, char *argv[]) {
	Solution * sol = new Solution();
	cout << sol->minDistance("woods", "waodous") << endl;
	return 0;
}
