/**
 * LeetCode Q131 - Palindrome Partioning
 *
 * Given a string s, partition s such that every substring of the 
 * partition is a palindrome.
 * 
 * Return all possible palindrome partitioning of s.
 * 
 * For example, given s = "aab",
 * Return
 * 
 * [
 *   ["aa","b"],
 *   ["a","a","b"]
 * ]
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.size() == 0) return res;
        else {
            // Split all characters in s
            vector<string> split;
            for(int i = 0;i < (int)s.size();i++) split.push_back(string(&s[i], 1));
            res.push_back(split);
            // Check every char's palindrome
            for(int i = 0;i < (int) (split.size() - 1);i++) {
                int curPos = i;
                string temp = "";
                while(curPos >= 0 && 2 * i + 1 - curPos < (int)(split.size())&& split[curPos] == split[2 * i + 1 - curPos]) {
                    temp = split[curPos] + temp + split[2 * i + 1 - curPos];
                    curPos--;
                    
                }
                curPos = i - 1;
                while(c
            }
        }
        return res;
    }
};

int main() {
    Solution * sol = new Solution();
    vector<vector<string>> res = sol->partition("aab");
    cout << "[" << endl;
    for(int i = 0;i < (int)res.size();i++) {
        for (int j = 0;j < (int)res[i].size();j++) {
            cout << "\"" << res[i][j] << "\", ";
        }
        cout << endl;
    }
    cout << "]" << endl;
}
