/**
 * Given a 2D board and a word, find if the word exists in 
 * the grid.
 *
 * The word can be constructed from letters of sequentially 
 * adjacent cell, where "adjacent" cells are those horizontally 
 * or vertically neighboring. The same letter cell may not be 
 * used more than once.
 *
 * For example,
 * Given board =
 * 
 * [
 *   ['A','B','C','E'],
 *   ['S','F','C','S'],
 *   ['A','D','E','E']
 * ]
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool exist_dfs(vector<vector<char> >& board, int x, int y, string word) {
		if (word.size() == 1) return true;
		string newWord(word.begin() + 1, word.end());
		// Set the curr cell occupied
		board[x][y] = 0;
		// Traverse LEFT, UPPER, RIGHT, LOWER
		if (x - 1 >= 0 && board[x - 1][y] == newWord[0]) {
			if (exist_dfs(board, x - 1, y, newWord)) {
				return true;
			}
		}
		if (y - 1 >= 0 && board[x][y - 1] == newWord[0]) {
			if (exist_dfs(board, x, y - 1, newWord)) {
				return true;
			}
		}
		if (x + 1 < (int) board.size() && board[x + 1][y] == newWord[0]) {
			if (exist_dfs(board, x + 1, y, newWord)) {
				return true;
			}
		}
		if (y + 1 < (int) board[x].size() && board[x][y + 1] == newWord[0]) {
			if (exist_dfs(board, x, y + 1, newWord)) {
				return true;
			}
		}
		board[x][y] = word[0];
		return false;
	}

	bool exist(vector<vector<char> >& board, string word) {
		vector<vector<int> > vfirstCharPos(0);
		if (word.size() == 0) return false;
		for(int i = 0;i < (int) board.size();i++) {
			for(int j = 0;j < (int) board[i].size();j++) {
				if (board[i][j] == word[0]) {
					vfirstCharPos.push_back(vector<int>(2, 0));
					vfirstCharPos[vfirstCharPos.size() - 1][0] = i;
					vfirstCharPos[vfirstCharPos.size() - 1][1] = j;
				}
			}
		}

		for (int i = 0;i < (int) vfirstCharPos.size();i++) {
			vector<vector<char> > copyBoard;
			for (int j = 0;j < (int)board.size();j++) {
				copyBoard.push_back(vector<char>(board[j]));
			}
			if (exist_dfs(copyBoard, vfirstCharPos[i][0], vfirstCharPos[i][1], word)) {
				return true;
			}
		}
		return false;
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	char board[3][4] = {
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'}
	};
	vector<vector<char> > vboard;
	for (int i = 0;i < 3;i++) {
		vboard.push_back(vector<char>(board[i], board[i] + sizeof(board[i])/sizeof(char)));
	}
	cout << sol->exist(vboard, "ABCCED") << endl;
	cout << sol->exist(vboard, "SEE") << endl;
	cout << sol->exist(vboard, "ABCB") << endl;
	return 0;
}
