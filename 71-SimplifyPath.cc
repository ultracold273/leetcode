/**
 * Given an absolute path for a file (Unix-style), simplify it.
 *
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 *
 * Corner Cases:
 *
 * * Did you consider the case where path = "/../"?
 *   * In this case, you should return "/".
 * * Another corner case is the path might contain multiple 
 * slashes '/' together, such as "/home//foo/".
 *   * In this case, you should ignore redundant slashes and 
 *   return "/home/foo".
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	string getToken(string path) {
		static int startPos = 0;
		while(path[startPos] == '/' && startPos < (int) path.size()) startPos++;
		for (int i = startPos;i < (int) path.size();i++) {
			if(path[i] == '/') {
				string res = path.substr(startPos, i - startPos);
				startPos = i;
				return res;
			}
		}
		if (startPos == (int) path.size()) {
			startPos = 0;
			return "";
		}else{
			string res = path.substr(startPos,  path.size() - startPos);
			startPos = path.size();
			return res;
		}
	}

	string simplifyPath(string path) {
		vector<string> pathList;
		int endPosition = 0;
		string token;
		while((token = getToken(path)) != "") {
			if (token == "..") {
				endPosition--;
				if(endPosition <= 0) endPosition = 0;
			}else if (token == ".") {
			}else{
				if (endPosition < pathList.size() && endPosition >= 0) {
					pathList[endPosition] = token;
				}else{
					pathList.push_back(token);
				}
				endPosition++;
			}
		}
		string res("/");
		for(int i = 0;i < endPosition;i++) {
			res += pathList[i];
			if (i != endPosition - 1) {
				res += "/";
			}
		}
		return res;
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
//	string token;
//	while((token = sol->getToken("/a/../b/c/adfsdqwe/df/")) != "") {
//		cout << token << endl;
//	}
//	while((token = sol->getToken("//..//btc/aa/dtf//")) != "") {
//		cout << token << endl;
//	}
//	while((token = sol->getToken("//..//rb/r/seems/ok")) != "") {
//		cout << token << endl;
//	}
	cout << sol->simplifyPath("/home/") << endl;
	cout << sol->simplifyPath("/a/./b/../../c/") << endl;
	cout << sol->simplifyPath("/home//foo/") << endl;
	cout << sol->simplifyPath("/../") << endl;
	return 0;
}
