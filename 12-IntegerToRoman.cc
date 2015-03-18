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
			string romanNumerals = "IVXLCDM";
			string s;
			switch(numLessThanTen) {
				case 0: s = "";break;
				case 1: s = romanNumerals.substr(order * 2, 1);break;
				case 2: s = romanNumerals.substr(order * 2, 1) + romanNumerals.substr(order * 2, 1);break;
				case 3: s = romanNumerals.substr(order * 2, 1) + romanNumerals.substr(order * 2, 1) + romanNumerals.substr(order * 2, 1);break;
				case 4: s = romanNumerals.substr(order * 2, 1) + romanNumerals.substr(order * 2 + 1, 1);break;
				case 5: s = romanNumerals.substr(order * 2 + 1, 1);break;
				case 6: s = romanNumerals.substr(order * 2 + 1, 1) + romanNumerals.substr(order * 2, 1);break;
				case 7: s = romanNumerals.substr(order * 2 + 1, 1) + romanNumerals.substr(order * 2, 1) + romanNumerals.substr(order * 2, 1);break;
				case 8: s = romanNumerals.substr(order * 2 + 1, 1) + romanNumerals.substr(order * 2, 1) + romanNumerals.substr(order * 2, 1) + romanNumerals.substr(order * 2, 1);break;
				case 9: s = romanNumerals.substr(order * 2, 1) + romanNumerals.substr(order * 2 + 2, 1);break;
			}
			return s;
		}

		string intToRoman(int num) {
			string s = "";
			int order = 0;
			do{
				s = findRomanStr(num % 10, order) + s;
				num /= 10;
				order++;
			}while(num > 0);
			return s;
		}
};
