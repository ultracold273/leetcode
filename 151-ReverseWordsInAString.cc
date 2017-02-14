/**
 * LeetCode Q151 - Reverse Words in a String
 * Given an input string, reverse the string word by word.
 *
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 *
 * Update (2015-02-12):
 * For C programmers: Try to solve it in-place in O(1) space.
 */
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    void reverseWord(string &s, int startIdx, int endIdx) {
        while(startIdx < endIdx) {
            char temp = s[startIdx];
            s[startIdx] = s[endIdx];
            s[endIdx] = temp;
            startIdx++;
            endIdx--;
        }
    }
    
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        // Reverse each word
        bool isWord = false;
        int wordSt = 0;
        for(int i = 0;i < (int)s.size();i++) {
            if (isWord && s[i] == ' ') {
                reverseWord(s, wordSt, i - 1);
                isWord = false;
            }else if (!isWord && s[i] != ' ') {
                isWord = true;
                wordSt = i;
            }
        }
        if (isWord) {
            reverseWord(s, wordSt, s.size() - 1);
        }
        // Reduce starting string and trailing string
        int lastSpace = s.size();
        bool consecutiveSpaces = false;
        for(int i = s.size() - 1;i >= 0;i--) {
            if (!consecutiveSpaces && s[i] == ' ') {
                lastSpace = i;
                consecutiveSpaces = true;
            }else if (consecutiveSpaces && s[i] != ' ') {
                int spaceLength = lastSpace - i;
                if (spaceLength > 1) s.erase(i + 1, spaceLength - 1);
                consecutiveSpaces = false;
            }
        }
        if (consecutiveSpaces) s.erase(0, lastSpace + 1);
        if (s[s.size() - 1] == ' ') s.erase(s.size() - 1, 1);
    }
};


int main() {
    Solution * sol = new Solution();
    string s("   a   b ");
    sol->reverseWords(s);
    cout << s << endl;
}
