/**
 * LeetCode Question 10 - Regular Expression Matching
 * Implement regular expression matching with support for '.' and '*'.
 * e.g., isMatch("aab", "c*a*b") -> true
 */

#include <iostream>
using namespace std;

class Solution {
	private:
		const char * findNextChar(const char * s, char nextChar) {
			while(*s != nextChar) {
				if (*s == '\0') return NULL;
				s++;
			}
			return s;
		}
	public:
		bool isMatch(const char *s, const char *p) {
			if (*p == '\0') {
				return *s == '\0';
			}
			if (*(p + 1) != '*') {
				if (*p != *s && *p != '.') return false;
				else return isMatch(s + 1, p + 1);
			}else{
				while((*p == '.' || *s == *p)) {
					if (isMatch(s, p + 2)) return true;
				}
				return isMatch(s, p + 2);
				/**
				if(*p != '.'){
					char present = *p;
					const char * ptr = p+2;
					int leastlength = 0;
					while(*ptr == present) {
						// If encounter continues * pattern, jump
						if (*(ptr+1) == '*') ptr += 2;
						else {
							leastlength++;
							ptr++;
						}
					}
					// Check whether there are enough present pattern
					while(*s == present) {
						s++;
						leastlength--;
					}
					if (leastlength > 0) return false;
					else{
						p = ptr;
						return isMatch(s, p);
					}
				}else{
					// Matching '.*' pattern
					if (*(p+2) == '\0') return true;
					else {
						char nextChar = * (p+2);
						return false;
						//
						const char * foundNextChar = findNextChar(s, nextChar);
						while(foundNextChar != NULL){
							if (isMatch(foundNextChar, p + 2) == true)
								return true;
							else
								foundNextChar = findNextChar(foundNextChar + 1, nextChar);
						}
						return false;
					}
				}
				**/
			}
		}
};

int main() {
	Solution * sol = new Solution();
	cout << "\"aa\", \"a\": " << sol->isMatch("aa", "a") << endl;
	cout << "\"aa\", \"aa\": " << sol->isMatch("aa", "aa") << endl;
	cout << "\"aaa\", \"aa\": " << sol->isMatch("aaa", "aa") << endl;
	cout << "\"aa\", \"a*\": " << sol->isMatch("aa", "a*") << endl;
	cout << "\"aa\", \".*\": " << sol->isMatch("aa", ".*") << endl;
	cout << "\"ab\", \".*\": " << sol->isMatch("ab", ".*") << endl;
	cout << "\"aab\", \"c*a*b\": " << sol->isMatch("aab", "c*a*b") << endl;
	cout << "\"aaa\", \"ab*a*c*a\": " << sol->isMatch("aaa", "ab*a*c*a") << endl; 
	return 0;
}
