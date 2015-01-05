/**
 * Leetcode Question 5
 * Given a string s, find the longest palindromic substring in S.
 * You may assume that the maximum length of S is 1000, and there exists
 * one unique longest palindromic substring.
 * Start Date: Dec. 19, 2014
 */

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
	private:
		bool isPalindrome(string s, int st, int len) {
			int end = st + len - 1, start = st;
			while(start <= end) {
				if (s[start] != s[end]) {
					return false;
				}
				start++;
				end--;
			}
			return true;
		}
	public:
		string longestPalindrome(string s) {
			int maxlen = 0;
			int maxSt = 0;
			for (int center = 0; center < (int) s.size(); center++) {
				// Single Center
				int st = center;
				int ed = center;
				while(st >= 0 && ed < (int) s.size() && s[st] == s[ed]) {
					st--;
					ed++;
				}
				st++;
				ed--;
				if(ed - st + 1 > maxlen) {
					maxlen = ed - st + 1;
					maxSt = st;
				}

				// Double Center
				st = center;
				ed = center + 1;

				while(st >= 0 && ed < (int) s.size() && s[st] == s[ed]) {
					st--;
					ed++;
				}
				st++;
				ed--;
				if(ed - st + 1 > maxlen) {
					maxlen = ed - st + 1;
					maxSt = st;
				}
			}
			return s.substr(maxSt, maxlen);
		}
		/*
		string longestPalindrome(string s) {
			int maxlen = 0;
			int maxSt = 0;
			for (int st = 0; st < s.size(); st++) {
				for(int ed = s.size() - 1; ed >= st; ed--) {
					if (ed - st + 1 < maxlen) break;
//					string testStr = s.substr(st, ed - st + 1);
					if (isPalindrome(s, st, ed - st + 1)) {
						if (ed - st + 1 > maxlen) {
							maxlen = ed - st + 1;
							maxSt = st;
//							maxStr = s.substr(st, ed - st + 1);
							printf("%d %s\n", maxlen, s.substr(maxSt, maxlen).c_str());
						}
					}
				}
			}
			return s.substr(maxSt, maxlen);
		}
		*/
};

int main() {
	Solution * a = new Solution();
	string temp = a->longestPalindrome("zudfweormatjycujjirzjpyrmaxurectxrtqedmmgergwdvjmjtstdhcihacqnothgttgqfywcpgnuvwglvfiuxteopoyizgehkwuvvkqxbnufkcbodlhdmbqyghkojrgokpwdhtdrwmvdegwycecrgjvuexlguayzcammupgeskrvpthrmwqaqsdcgycdupykppiyhwzwcplivjnnvwhqkkxildtyjltklcokcrgqnnwzzeuqioyahqpuskkpbxhvzvqyhlegmoviogzwuiqahiouhnecjwysmtarjjdjqdrkljawzasriouuiqkcwwqsxifbndjmyprdozhwaoibpqrthpcjphgsfbeqrqqoqiqqdicvybzxhklehzzapbvcyleljawowluqgxxwlrymzojshlwkmzwpixgfjljkmwdtjeabgyrpbqyyykmoaqdambpkyyvukalbrzoyoufjqeftniddsfqnilxlplselqatdgjziphvrbokofvuerpsvqmzakbyzxtxvyanvjpfyvyiivqusfrsufjanmfibgrkwtiuoykiavpbqeyfsuteuxxjiyxvlvgmehycdvxdorpepmsinvmyzeqeiikajopqedyopirmhymozernxzaueljjrhcsofwyddkpnvcvzixdjknikyhzmstvbducjcoyoeoaqruuewclzqqqxzpgykrkygxnmlsrjudoaejxkipkgmcoqtxhelvsizgdwdyjwuumazxfstoaxeqqxoqezakdqjwpkrbldpcbbxexquqrznavcrprnydufsidakvrpuzgfisdxreldbqfizngtrilnbqboxwmwienlkmmiuifrvytukcqcpeqdwwucymgvyrektsnfijdcdoawbcwkkjkqwzffnuqituihjaklvthulmcjrhqcyzvekzqlxgddjoir");
	printf("%s\n", temp.c_str());
	return 0;
}
