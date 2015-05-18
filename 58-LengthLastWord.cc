/**
 * Given a string s consists of 
 * upper/lower-case alphabets and empty space 
 * characters ' ', 
 * return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space characters only.
 * For example,
 * Given s = "Hello World",
 * return 5. 
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int strSize = s.size();
        int count = 0;
        while(s[strSize - 1] == ' ' && strSize > 0) strSize--;
        for (int i = strSize - 1;i >= 0;i--) {
            if(s[i] == ' ') break;
            else count++;
        }
        return count;
    }
};