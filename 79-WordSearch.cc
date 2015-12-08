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

#include <iosteam>
#include <vector>
using namespace std;

class Solution {
public:
	bool exist(vector<vector<char> >& board, string word) {

	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	char board[][] = {{'A', 'B', 'C', 'E'},
				 {'S', 'F', 'C', 'S'},
				 {'A', 'D', 'E', 'E'}};
	vector<vector<char> > vboard;
	for (int i = 0;i < 3;i++) {
		vboard.push_back(vector<char>(board[i], board[i] + sizeof(board[i])/sizeof(char)));
	}
	cout << sol->exist(vboard, "ABCCED") << endl;
	cout << sol->exist(vboard, "SEE") << endl;
	cout << sol->exist(vboard, "ABCB") << endl;
	return 0;
}