/*
 * LeetCode 126 - Word Ladder II
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, 
 * find all shortest transformation sequence(s) from beginWord to endWord, 
 * such that:
 *
 * Only one letter can be changed at a time
 * Each intermediate word must exist in the word list
 *
 * For example,
 *
 *   Given:
 *   beginWord = "hit"
 *   endWord = "cog"
 *   wordList = ["hot","dot","dog","lot","log"]
 *
 *   Return
 *
 *   [
 *      ["hit","hot","dot","dog","cog"],
 *      ["hit","hot","lot","log","cog"]
 *   ]
 *
 * Note:
 *
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 *
 */

/*
 * One of the tricky things about the problem is 
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public: 
    int getEditDistanceSimple(string beginWord, string endWord) {
        int editDist = 0;
        for (int i = 0;i < (int) beginWord.size();i++) {
            if (beginWord[i] != endWord[i]) editDist++;
        }
        return editDist;
    }

    vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string> > res;
        return res;
    } 
};
