/**
 * LeetCode Question 3
 * Description: Given a string, find the length of the longest substring
 * without repeating characters.
 * For example, the longest 
 *
 *
 * End Date: Dec. 19, 2014
 */

#include <stdio.h>
#include <string>
#include <map>

using namespace std;

class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int maxlen = 0;
			int len = 0;
			map <char, int> charMap;
			int repeatedPos;
			for (int i = 0;i < s.size();i++) {
				if (charMap.count(s[i]) != 0) {
//					printf("%d %d %d\n", i, len, maxlen);
					if(len > maxlen) {
						maxlen = len;
					}
					repeatedPos = charMap[s[i]];
					for (int j = i - len; j < repeatedPos;j++) {
						charMap.erase(s[j]);
					}
					charMap[s[i]] = i;
					len = i - repeatedPos;
				}else {
					charMap[s[i]] = i;
					len++;
				}
			}
			if (len > maxlen) maxlen = len;
			return maxlen;
		}
};

int main() {
	Solution * a = new Solution();
//	int b =	a->lengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");
	int b = a->lengthOfLongestSubstring("qopubjguxhxdipfzwswybgfylqvjzhar");
	printf("Answer: %d\n", b);
	return 0;
}
