/**
 * Given a string, determine if it is a palindrome, 
 * considering only alphanumeric characters and ignoring cases.
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 * Note:
 * Have you consider that the string might be empty? 
 * This is a good question to ask during an interview.
 * For the purpose of this problem, 
 * we define empty string as valid palindrome. 
 */

#include <iostream>
using namespace std;

class Solution {
	public:
		bool isAlphaNumeric(char a) {
			if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')
					|| (a >= '0' && a <= '9'))
				return true;
			else
				return false;
		}

		bool isValidPair(char a, char b) {
			if (isAlphaNumeric(a) && isAlphaNumeric(b)) {
				if (a == b) return true;
				else if (a - b == 'a' - 'A' || a - b == 'A' - 'a') return true;
				else return false;
			}
			return false;
		}

		bool isPalindrome(string s) {
			int start = 0;
			int end = s.size() - 1;
			/**
			int allEmpty = 1;
			// Detect the special condition all empty
			for(int i = 0;i < (int) s.size();i++) {
				if (s[i] != ' ') {
					allEmpty = 0;
					break;
				}
			}

			if (allEmpty == 1) return true;
			*/


			while(start < (int) s.size() && !isAlphaNumeric(s[start])) start++;
			while(end > 0 && !isAlphaNumeric(s[end])) end--;
			
			if(start > end) return true;

			while(start < end) {
				while(start < (int) s.size() && !isAlphaNumeric(s[start])) start++;
				while(end > 0 && !isAlphaNumeric(s[end])) end--;
//				printf("%c %c\n", s[start], s[end]);
				cout << s[start] << ' ' << s[end] << endl;
				if(!isValidPair(s[start], s[end])) {
					return false;
				}
				start++;
				end--;
			}
			return true;
		}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	string s = "A man, a plan, a canal: Panama";
	sol->isPalindrome(s);

	return 0;
}
