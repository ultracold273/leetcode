/*
 * LeetCode 127 - Word Ladder
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, 
 * find all shortest transformation sequence(s) from beginWord to endWord, 
 * such that:
 *
 *   1. Only one letter can be changed at a time
 *   2. Each intermediate word must exist in the word list
 *
 * For example,
 *
 *   Given:
 *   beginWord = "hit"
 *   endWord = "cog"
 *   wordList = ["hot","dot","dog","lot","log"]
 *
 *   As one shortest transformation is 
 *          "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 *   Return its length 5.
 *
 * Note:
 *
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public: 
    bool isDistanceOne(string beginWord, string endWord) {
        int dist = 0;
        if (beginWord.size() != endWord.size()) return false;
        else {
            for(int i = 0;i < (int)beginWord.size();++i) {
                if (beginWord[i] != endWord[i]) dist++;
                if (dist > 1) break;
            }
            return (dist == 1);
        }
    }

    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) { 
        vector<string> curString;
        vector<string> nxtString;
        int length = 1;
        curString.push_back(beginWord);
        while(!curString.empty()) {
            for(auto str_it = curString.begin();str_it != curString.end();++str_it) {
                if (isDistanceOne(*str_it, endWord)) return length + 1;
                else {
                    vector<unordered_set<string>::iterator> its;
                    for(auto it = wordList.begin();it != wordList.end();++it) {
                        if (isDistanceOne(*str_it, *it)) {
                            nxtString.push_back(*it);
                            its.push_back(it);
//                            wordList.erase(it);
                        }
                    }
                    for (auto it = its.begin();it != its.end();++it) {
                        wordList.erase(*it);
                    }
                }
            }
            length++;
            curString = nxtString;
            nxtString.clear();
        }
        return 0;
    }
};

int main() {
    Solution * sol = new Solution();
    string beginWord = "hit";
    string endWord = "cog";
    unordered_set<string> wordList({"hot", "dot", "dog", "lot", "log"});
    cout << sol->ladderLength(beginWord, endWord, wordList) << endl;
}
