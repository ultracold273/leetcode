/**
 * Given a string containing just the characters
 * '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 * 
 * The brackets must close in the correct order, 
 * "()" and "()[]{}" are all valid but "(]" 
 * and "([)]" are not.
 */

 #include <iostream>
 #include <string>
 #include <vector>
 using namespace std;

 class Solution {
 public:
 	bool isValid(string s) {
 		vector<char> v;
 		int n = s.size();
 		for (int i = 0; i < n; ++i)
 		{
 			if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
 				v.push_back(s[i]);
 			}else if (s[i] == ')') {
 				if ( v.size() == 0 || v.back() != '(' ) return false;
 				else {
 					v.pop_back();
 				}
 			}else if(s[i] == ']') {
 				if ( v.size() == 0 || v.back() != '[' ) return false;
 				else {
 					v.pop_back();
 				}
 			}else if(s[i] == '}') {
 				if ( v.size() == 0 || v.back() != '{' ) return false;
 				else {
 					v.pop_back();
 				}
 			}
 		}
 		if (v.size() == 0) return true;
 		else return false;
 	}
 }