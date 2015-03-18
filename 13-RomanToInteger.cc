/**
 * Given an roman numeral, convert it to a integer.
 * Input is guaranteed to be within the range from 1 to 3999
 *
 */

#include <iostream>
using namespace std;

class Solution {
	public:
		int pow(int base, int power) {
			int res = 1;
			for (int i = 0;i < power;i++) {
				res *= base;
			}
			return res;
		}
		int romanToInt(string s) {
			string rmNum = "IVXLCDM";
			int num = 0;
			int index = 0;
			while(index < (int) s.size()) {
				int sdx = rmNum.find(s[index]);
				cout << sdx << endl;
				int sdx2;
				// Two Special Cases: 4 and 9
				if(index < (int) s.size() - 1 && (sdx2 = rmNum.find(s[index + 1])) - sdx > 0) {
					if (sdx2 - sdx == 1) {
						num += 4 * ((sdx % 2)?5:1) * pow(10, (sdx / 2));
					} else if (sdx2 - sdx == 2) {
						num += 9 * ((sdx % 2)?5:1) * pow(10, (sdx / 2));
					}
					index++;
				}else{
					num += ((sdx % 2)?5:1) * pow(10, (sdx / 2));
				}
				index++;
			}
			return num;
		}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	string s = "CDXLIV";
	cout << sol->romanToInt(s) << endl;
	return 0;
}
