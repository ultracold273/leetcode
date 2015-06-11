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

#define NO_INPUT 0
#define EXP_NUM 1
#define DECIMAL_NUM 2
#define NORMAL_NUM 3
#define INVALID 4
#define DETECT_E 5
#define DETECT_P 6
#define DETECT_P_NONUM 7
#define NEG_SIGN 8
#define SIGN 9

class Solution {
public:
	int trim(string s) {
		int edPos;
		for (edPos = s.size();edPos > 0;edPos--) {
			if(s[edPos - 1] != ' ') break;
		}
		return edPos;
	}

	bool isNumber(string s) {
		int edPos = trim(s);
		int state = NO_INPUT;
		for (int i = 0;i < edPos;i++) {
			switch(state) {
				case NO_INPUT:
					if (s[i] >= '0' && s[i] <= '9') {
						state = NORMAL_NUM;
					}else if (s[i] == '.') {
						state = DETECT_P_NONUM;
					}else if (s[i] == ' ') {
					}else if (s[i] == '-' || s[i] == '+') {
					    state = SIGN;
					}else{
						state = INVALID;
					}
					break;
				case DETECT_E:
					if (s[i] >= '0' && s[i] <= '9') {
						state = EXP_NUM;
					}else if(s[i] == '-' || s[i] == '+') {
						state = NEG_SIGN;
					}else{
						state = INVALID;
					}
					break;
				case NEG_SIGN:
					if (s[i] >= '0' && s[i] <= '9') {
						state = EXP_NUM;
					}else {
						state = INVALID;
					}
					break;
				case DETECT_P_NONUM:
				    if (s[i] >= '0' && s[i] <= '9') {
						state = DECIMAL_NUM;
					}else{
						state = INVALID;
					}
					break;
				case DETECT_P:
					if (s[i] >= '0' && s[i] <= '9') {
						state = DECIMAL_NUM;
					}else if (s[i] == 'e' || s[i] == 'E') {
					    state = DETECT_E;
					}else{
						state = INVALID;
					}
					break;
				case EXP_NUM:
					if (s[i] >= '0' && s[i] <= '9') {
					}else{
						state = INVALID;
					}
					break;
				case DECIMAL_NUM:
					if (s[i] >= '0' && s[i] <= '9') {
					}else if (s[i] == 'e' || s[i] == 'E') {
						state = DETECT_E;
					}else{
						state = INVALID;
					}
					break;
				case SIGN:
				    if (s[i] >= '0' && s[i] <= '9') {
				        state = NORMAL_NUM;
					}else if(s[i] == '.') {
						state = DETECT_P_NONUM;
					}else{
					    state = INVALID;
					}
					break;
				case NORMAL_NUM:
					if (s[i] >= '0' && s[i] <= '9') {
					}else if(s[i] == '.') {
						state = DETECT_P;
					}else if(s[i] == 'e' || s[i] == 'E') {
						state = DETECT_E;
					}else{
						state = INVALID;
					}
					break;
				case INVALID:return false;break;
				default: break;
			}
		}
		return (state == EXP_NUM) || (state == DECIMAL_NUM) || (state == NORMAL_NUM) || (state == DETECT_P);
	}

	bool isNumber_deprecated(string s) {
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
	cout << (sol->isNumber("1. ")) << ":1" << endl;
	cout << (sol->isNumber("1e")) << ":0" << endl;
	cout << (sol->isNumber("1e 1")) << ":0" << endl;
	cout << (sol->isNumber("1. 1")) << ":0" << endl;
	cout << (sol->isNumber(". 1")) << ":0" << endl;
	cout << (sol->isNumber(".")) << ":0" << endl;
	cout << (sol->isNumber(" -.")) << ":0" << endl;
}
