/**
 * Leetcode 32 - Longest Valid Parentheses
 * Given a string containing just the characters '(' and ')',
 * find the length of the longest valid (well-formed) parentheses
 * substring.
 * For "(()", the longest valid parentheses substring is "()",
 * which has length = 2.
 *
 * Another example is ")()())", where the longest valid parentheses
 * substring is "()()", which has length = 4.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
	public:
		int longestValidParentheses(string s) {
			int strSize = s.size();
			int longestValid = 0;
			vector<vector<int> > vecLength;
			vector<int> stkPosLeftParenthesis;
			for(int i = 0;i < strSize;i++) {
//				cerr << s[i];
				if (s[i] == '(') {
					stkPosLeftParenthesis.push_back(i);
				}else{
					if (stkPosLeftParenthesis.size() != 0) {
						// matched parenthesis
						int lastPos = stkPosLeftParenthesis.back();
						stkPosLeftParenthesis.pop_back();
						// Search and merge
						vector<vector<int> >::iterator it = vecLength.end();
						it--;
						while(it != (--vecLength.begin()) && (*it)[0] > lastPos) {
							vector<vector<int> >::iterator temp = it;
							it--;
							vecLength.erase(temp);
						}
						if (it == (--vecLength.begin())) {
							vector<int> aTuple;
							aTuple.push_back(lastPos);
							aTuple.push_back(i - lastPos + 1);
							vecLength.push_back(aTuple);
						} else {
							if ((*it)[0] + (*it)[1] == lastPos) {
								vector<int> aTuple;
								aTuple.push_back((*it)[0]);
								aTuple.push_back((*it)[1] + i - lastPos + 1);
								vecLength.push_back(aTuple);
							}
						}
					}else{
						// Unmatched parenthesis
					}
				}
			}
			for (vector<vector<int> >::iterator it = vecLength.begin();it != vecLength.end();it++) {
				if((*it)[1] >= longestValid) {
					longestValid = (*it)[1];
				}
			}
			return longestValid;
		}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	string s1("(()");
	cout << sol->longestValidParentheses(s1) << endl;

	string s2(")()())");
	cout << sol->longestValidParentheses(s2) << endl;

	string s3("()(()");
	cout << sol->longestValidParentheses(s3) << endl;

	string s4("(()(((()");
	cout << sol->longestValidParentheses(s4) << endl;

	string s5("()(()");
	cout << sol->longestValidParentheses(s5) << endl;

	string s6("(()()");
	cout << sol->longestValidParentheses(s6) << endl;
	return 0;
}
