/**
 * Implement strStr().
 *
 * Returns the index of the first occurrence of needle in haystack, 
 * or -1 if needle is not part of haystack.
 */

 #include <iostream>
 #include <string.h>
 using namespace std;

 class Solution {
 public:
 	int strStr(char * haystack, char * needle) {
 		int i = 0;
 		//int lengthHay = strlen(haystack);
 		//int lengthNeedle = strlen(needle);
 		if (haystack[0] == '\0' && needle[0] == '\0') return 0;
 		while(haystack[i] != '\0') {
 			int ptrHay = i;
 			int ptrNeedle = 0;
 			while((haystack[ptrHay] != '\0' && needle[ptrNeedle] != '\0') && 
 				haystack[ptrHay] == needle[ptrNeedle]) {ptrHay++;ptrNeedle++;}
 			if (needle[ptrNeedle] == '\0') return i;
 			if (haystack[ptrHay] == '\0') return -1;
 			i++;
 		}
 		return -1;
 	}
 };

 int main(int argc, char const *argv[])
 {
 	Solution * sol = new Solution();
 	char haystack[] = "abbbaaaaaaabbababbbbabababbbbbbbaaaaaaabbaaabbaababbbbababababaabbbbbbaaaaababbbbaaabababbbaaaabbbaabbbbbbabababbabaaaaabaabaaababbbaaabaababbaaabaaababbabbbbababaaaaaaababaabaabbaabbbaaabaaaaaa";
 	char needle[] = "aabaaaabababbbabababbbaabaabaaaaabaabbbaabbbbba";
 	cout << sol->strStr(haystack, needle) << endl;
 	return 0;
 }

