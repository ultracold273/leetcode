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

class Vertex {
public:
    string word;
    vector<Vertex *> edges;

    Vertex(string name) {
        this->word = name;
    }
};

class Solution {
public: 
    int getEditDistanceSimple(string beginWord, string endWord) {
        int editDist = 0;
        for (int i = 0;i < (int) beginWord.size();i++) {
            if (beginWord[i] != endWord[i]) editDist++;
        }
        return editDist;
    }

	void connectGraph(Vertex &begin, Vertex &end, vector<Vertex *> &wordVertexes) {
		bool anyDisOne = false;
		if (1 == getEditDistanceSimple(begin.word, end.word)) {
			begin.edges.push_back(&end);
			return;
		}
		vector<Vertex *> cur;
		cur.push_back(&begin);
		do {
			for (auto it = wordVertexes.begin(); it != wordVertexes.end(); ++it) {
			}
		}while(anyDisOne && wordVertexes.size() != 0);
	}

    vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string> > res;
        // First build a graph starting from beginWord
        Vertex * ver_begin = new Vertex(beginWord);
		Vertex * ver_end = new Vertex(endWord);
		vector<Vertex *> wordVertexes;
        for (auto it = wordList.begin(); it != wordList.end(); ++it) {
			Vertex * graph_ver = new Vertex(*it);
			wordVertexes.push_back(graph_ver);
        }
		connectGraph(*ver_begin, *ver_end, wordVertexes);
        return res;
    } 
};
