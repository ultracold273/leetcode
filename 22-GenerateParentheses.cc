/**
 * Given n pairs of parentheses, write a function
 * to generate all combinations of well-formed 
 * parentheses.
 * For example,
 * given n = 3, a solution set is:
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 */

 #include <iostream>
 #include <vector>
 #include <string>
 using namespace std;

 class Solution {
 public:
 	vector<string> generateParenthesis(int n) {
 		int budget = n;
 		vector<string> res;
 		int stc = 0;
 		string s = "";
 		recGenerateParenthesis(res, stc, s, budget);
 		return res;
 	}

 	void recGenerateParenthesis(vector<string> &res, int stc, string s, int budget) {
 		if (budget == 0) {
 			while(stc > 0) {
 				s.push_back(')');
 				stc--;
 			}
 			res.push_back(s);
 			return;
 		}else {
 			if (stc == 0) {
 				s.push_back('(');
 				budget--;
 				stc++;
 				recGenerateParenthesis(res, stc, s, budget);
 			}else {
 			s.push_back(')');
 			stc--;
 			recGenerateParenthesis(res, stc, s, budget);
 			s = s.substr(0, s.size() - 1);
 			stc++;
 			s.push_back('(');
 			budget--;
 			stc++;
 			recGenerateParenthesis(res,stc, s, budget);
			}
 		}
 	}
 };

int main(int argc, char const *argv[])
{
	Solution * sol = new Solution();
	std::vector<string> vStr = sol->generateParenthesis(3);
	for(int i = 0;i < vStr.size();i++) {
		cout << vStr[i] << endl;
	}
	return 0;
}