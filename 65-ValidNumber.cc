/**
 * Validate if a given string is numeric.
 *
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 *
 * Note: It is intended for the problem statement to be ambiguous. 
 * You should gather all requirements up front before implementing one. 
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		int strSize = s.size();
		bool acceptDigit = true;
		bool acceptDecimal = true;
		bool acceptSpace = true;
		bool acceptSci = false;
//		bool mustDigit = false;
		bool digitsDetected = false;
		bool ending = false;
//		bool spaceStreak = false;
		for (int i = 0;i < strSize;i++) {
			if ((s[i] >= '0' && s[i] <= '9') || s[i] == '.' || s[i] == ' ' || s[i] == 'e') {
				if (s[i] == '.') {
//					if (mustDigit || isDecimal || isExponent || spaceStreak) return false;
					if (!acceptDecimal) return false;
//					mustDigit = true;
					acceptDecimal = false;
					if (!digitsDetected) {
						acceptSci = false;
					}
				}else if (s[i] == 'e') {
//					if (mustDigit || isExponent || (!digitsDetected) || spaceStreak) return false;
					if (!acceptSci) return false;
					acceptSci = false;
					acceptSpace = false;
					acceptDecimal = false;
					ending = false;
				}else if (s[i] == ' ') {
					if (!acceptSpace) return false;
					if (digitsDetected) {
						acceptSci = false;
						acceptDigit = false;
						acceptDecimal = false;
						acceptSpace = true;
					}
				}else {
					if (!acceptDigit) return false;
					if (!digitsDetected) {
						digitsDetected = true;
						acceptSci = true;
					}
					ending = true;
				}
			}else
				return false;
		}
		return digitsDetected && ending;
	}
};

int main(int argc, char ** argv) {
	Solution * sol = new Solution();
	cout << (sol->isNumber("0")) << ":1" << endl;
	cout << (sol->isNumber(" 0.1 ")) << ":1" << endl;
	cout << (sol->isNumber("abc")) << ":0" << endl;
	cout << (sol->isNumber("1 a")) << ":0" << endl;
	cout << (sol->isNumber("2e10")) << ":1" << endl;
	cout << (sol->isNumber(" ")) << ":0" << endl;
	cout << (sol->isNumber(".1")) << ":1" << endl;
	cout << (sol->isNumber("1.")) << ":1" << endl;
	cout << (sol->isNumber("1e")) << ":0" << endl;
	cout << (sol->isNumber("1e 1")) << ":0" << endl;
	cout << (sol->isNumber("1. 1")) << ":0" << endl;
	cout << (sol->isNumber(". 1")) << ":0" << endl;
}
