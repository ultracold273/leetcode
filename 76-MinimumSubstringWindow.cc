/*
 * Given a string S and a string T, find the minimum window 
 * in S which will contain all the characters in T in 
 * complexity O(n).
 * 
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 * 
 * Note:
 * If there is no such window in S that covers all characters in T, 
 * return the emtpy string "".
 *
 * If there are multiple such windows, you are guaranteed that 
 * there will always be only one unique minimum window in S.
 */

 /* 
  * First find a range that contains all the characters in it
  * then shrink the starting point until there are all 
  */

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty())
            return "";
        int t_map[256] = {0}, s_map[256] = {0};
        int t_size = 0;

        for (auto c : t)
        {
            if (t_map[c] == 0)
                t_size ++;
            t_map[c] ++;
        }
        int start = 0, end = 0, found = 0, min_start = 0, min_end = s.size() + 1;
        while (start <= end && end <= s.size())
        {
            if (found < t_size)
            {
                end ++;
                char c = s [end - 1];
                if (t_map[c] > 0 && ++s_map[c]  ==  t_map[c])
                {
                    found ++;
                }
            }else {
                start ++;
                char c = s [start - 1];
                if (t_map[c] > 0 && s_map[c]--  ==  t_map[c])
                {
                    found --;
                }
            }
            if (found == t_size && end - start < min_end - min_start)
            {
                min_start = start;
                min_end = end;
            }
        }
        if (min_end == s.size() + 1)
            return "";
        return s.substr(min_start, min_end - min_start);
    }
};
int main(int argc, char const *argv[])
{
	Solution * sol = new Solution();
	return 0;
}
