/**
 * LeetCode Question 10 - Regular Expression Matching
 * Implement regular expression matching with support for '.' and '*'.
 * e.g., isMatch("aab", "c*a*b") -> true
 */

#include <iostream>
using namespace std;

class Solution {
	private:
		bool EndMatch(const char *p) {
			if (*p == '\0') return true;
			if (*p == '.') {
			}else{
			}
		}
	public:
		bool isMatch(const char *s, const char *p) {
			if (*s == '\0') {
				return EndMatch(p);
			}

			return false;
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
	return 0;
}
