/**
 * LeetCode Question 6 - ZigZag Conversion
 * 
 *
 *
 */

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
	public:
		string convert(string s, int nRows) {
			if (nRows <= 1 || nRows >= (int) s.size()) return s;
			vector<string> r(nRows);
			int row = 0;
			int step = 1;
			for (int i = 0;i < (int) s.size(); i++) {
				if (row == 0) step = 1;
				if (row == nRows - 1) step = -1;
				r[row] += s[i];
				row += step;
			}

			string res;
			for (int i = 0;i < nRows; i++) {
				res += r[i];
			}
			return res;
		}
};

int main() {
	Solution * sol = new Solution();
	printf("%s\n", sol->convert("PAYPALISHIRING", 3).c_str());
}

