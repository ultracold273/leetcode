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

#include <iostream>
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

    vector<int> addNext(string word, string endWord, unordered_set<string> &wordList, vector<string> &vertex, int level_end, bool &endWordFind) {
        vector<int> e;
        if (!endWordFind) {
            if (isDistanceOne(word, endWord)) {
                e.push_back(vertex.size());
                vertex.push_back(endWord);
                endWordFind = true;
                return e;
            }
        }else{
            if (isDistanceOne(word, endWord)) {
                e.push_back(vertex.size() - 1);
                return e;
            }
        }

        for(int i = level_end;i < (int) vertex.size();++i) {
            if (isDistanceOne(word, vertex[i])) {
                e.push_back(i);
            }
        }

        for (int p = 0; p < (int)word.length(); p++) {
            char letter = word[p];
            for (int k = 0; k < 26; k++) { 
                word[p] = 'a' + k;
                if (wordList.find(word) != wordList.end()) {
                    e.push_back((int) vertex.size());
                    vertex.push_back(word);
                }
                wordList.erase(word);
            }
            word[p] = letter;
        }
        return e;
    }

    void findPath_dfs(int st, int ed, vector<string> &vertex, vector<vector<int>> &edges, vector<int> &curPath, vector<vector<string>> &res) {
        if (st == ed) {
            vector<string> vecStr;
            for (auto it = curPath.begin();it != curPath.end();++it) {
                vecStr.push_back(vertex[*it]);
            }
            vecStr.push_back(vertex[ed]);
            res.push_back(vecStr);
        }else {
            curPath.push_back(st);
            for(auto it = edges[st].begin();it != edges[st].end();it++) {
                findPath_dfs(*it, ed, vertex, edges, curPath, res);
            }
            curPath.pop_back();
        }
    }

    vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<string> vertex;
        vector<vector<int>> edges;
        vector<vector<string> > res;
        vertex.push_back(beginWord);
        int level_st = 0;
        int level_end = 1;
        bool end = false;
        bool endWordFind = false;
        while(!end) {
            vector<int> edge;
            for(int i = level_st;i < level_end;++i) {
                edge = addNext(vertex[i], endWord, wordList, vertex, level_end, endWordFind);
                edges.push_back(edge);
            }
            if ((int) vertex.size() == level_end || endWordFind) {
                end = true;
            }
            level_st = level_end;
            level_end = vertex.size();
        }
/*        
        for(auto it = edges.begin();it != edges.end();++it) {
            for(auto it_n = (*it).begin();it_n != (*it).end();++it_n) {
                cout << *it_n << " " ;
            }
            cout << endl;
        }
*/
        if (endWordFind) {
            vector<int> curP;
            findPath_dfs(0, vertex.size() - 1, vertex, edges, curP, res);
        }
        return res;
    } 
};

int main() {
    Solution * sol = new Solution();
    string beginWord = "teach";
    string endWord = "place";
//    unordered_set<string> wordList({"hot", "dot", "dog", "lot", "log"});
    unordered_set<string> wordList({"peale","wilts","place","fetch","purer","pooch","peace","poach","berra","teach","rheum","peach"});
    vector<vector<string> > vecStr;
    vecStr = sol->findLadders(beginWord, endWord, wordList);
    for(auto it = vecStr.begin();it != vecStr.end();++it) {
        for(auto it_n = (*it).begin();it_n != (*it).end();++it_n) {
            cout << *it_n << " " ;
        }
        cout << endl;
    }
}
