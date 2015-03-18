/**
 * Given an integer, convert it to a roman numeral.
 * Input is guaranteed to be within the range from 1 to 3999
 *
 */

#include <iostream>
using namespace std;

class Solution {
	public:
		string findRomanStr(int numLessThanTen, int order) {
			string romanNumerals = "IVXLCDM"
			string
		}

		string intToRoman(int num) {
			string s = "";
			int order = 0;
			do{
				s = findRomanStr(num % 10, order) + s;
				num /= 10;
				order++;

			}while(num > 10);
			return s;
		}
};
