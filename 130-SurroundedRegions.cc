/**
 * LeetCode Q130 - Surrounded Regions
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), 
 * capture all regions surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that 
 * surrounded region.
 *
 * For example,
 *
 *  X X X X
 *  X O O X
 *  X X O X
 *  X O X X
 *
 * After running your function, the board should be:
 *
 *  X X X X
 *  X X X X
 *  X X X X
 *  X O X X
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve_rec(vector<vector<char>>& board, int i, int j) {
        int rows = board.size();
        int cols = board[0].size();
        board[i][j] = 'E';
        if (i != 0 && board[i-1][j] == 'O') {
            solve_rec(board, i - 1, j);
        }
        if (i != rows - 1 && board[i+1][j] == 'O') {
            solve_rec(board, i + 1, j);
        }
        if (j != cols - 1 && board[i][j+1] == 'O') {
            solve_rec(board, i, j + 1);
        }
        if (j != 0 && board[i][j-1] == 'O') {
            solve_rec(board, i, j - 1);
        }
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows == 0) return;
        int cols = board[0].size();
        // Update Cells connecting with 'O's in first Row and last row
        for(int j = 0;j < cols;++j) {
            if (board[0][j] == 'O') {
                solve_rec(board, 0, j);
            }
            if (board[rows - 1][j] == 'O') {
                solve_rec(board, rows - 1, j);
            }
        }
        // Update Cells connecting with 'O's in first Col and last col
        for(int i = 1;i < rows - 1;++i) {
            if (board[i][0] == 'O') {
                solve_rec(board, i, 0);
            }
            if (board[i][cols - 1] == 'O') {
                solve_rec(board, i, cols - 1);
            }
        }

        for (int i = 0;i < rows;++i) {
            for (int j = 0;j < cols;++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'E') board[i][j] = 'O';
            }
        }

    }
};

int main() {
    Solution * sol = new Solution();
    vector<vector<char>> board(250, vector<char>(250, 'X'));
    for (int j = 0;j < 250;++j){
        if (j % 2 == 0) 
            for (int i = 0;i < 250;i++) board[j][i] = 'O';
        else if (j % 4 == 1) board[j][249] = 'O';
        else board[j][0] = 'O';
    }
    sol->solve(board);
    for (int i = 0;i < board.size();++i) {
        for (int j = 0;j < board[0].size();++j) {
            cout << board[i][j] << ' ' ;
        }
        cout << endl;
    }
}
