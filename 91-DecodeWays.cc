/**
 * Leetcode Q91 - Decode Ways
 * A message containing letters from A-Z is being encoded to numbers 
 * using the following mapping:
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 *
 * Given an encoded message containing digits, determine the total 
 * number of ways to decode it.
 *
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) 
 * or "L" (12).
 *
 * The number of ways decoding "12" is 2. 
 */

#include <iostream>
#include <string>
using namespace std;

/*
 * This solution utilize dynamic programming， search from back of the
 * string.
 */
class Solution {
public:
    int numDecodings(string s) {
        int prevND = 0;
        int curND = 0;
        int tmp;
        bool zeroFlag = false;
        if (s.size() == 0) return 0;
        else if (s.size() == 1) {
            return (s[0] == '0') ? 0 : 1;
        }
        else {
            zeroFlag = (s[s.size() - 1] == '0');
            prevND = 1;
            curND = (zeroFlag)? 0 : 1;
            for(int i = s.size() - 2; i >= 0;i--) {
                if (zeroFlag) {
                    if (s[i] != '1' && s[i] != '2') return 0;
                    else {
                        curND = prevND;
                        prevND = 0;
                        zeroFlag = false;
                    }
                }else{
                    if (s[i] == '0') {
                        prevND = curND;
                        curND = 0;
                    }else if(s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')) {
                        tmp = curND + prevND;
                        prevND = curND;
                        curND = tmp;
                    }else{
                        prevND = curND;
                    }
                }
            }
            return curND;
        }
    }
};

int main(int argc, char * argv[]) {
    Solution * sol = new Solution();
    cout << sol->numDecodings("12") << endl;
    cout << sol->numDecodings("123") << endl;
    cout << sol->numDecodings("110") << endl;
    cout << sol->numDecodings("1010") << endl;

    return 0;
}
