/*
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * For example,
 * Consider the following matrix:
 *
 * [
 *  [1,   3,  5,  7],
 *  [10, 11, 16, 20],
 *  [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
*/

/*
 * First do binary search on the first elem of each row and then do binary search on each row
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        // First do binary search on first element of every row
        int left = 0;
        int right = matrix.size() - 1;
        int mid;
        int tgRow;
        // If target is less than the smallest
        if (target < matrix[0][0]) return false;
        while(left < right - 1) {
            mid = (left + right) / 2;
            if (target == matrix[mid][0]) return true;
            else if (target < matrix[mid][0]) {
            	right = mid - 1;
            }else {
            	left = mid;
            }
        }
        if (target == matrix[right][0] || target == matrix[left][0]) return true;
        else if (target > matrix[right][0]) tgRow = right;
        else tgRow = left;
        //cerr << tgRow << endl;

        // Do it again on the tgRow
        left = 0;
        right = matrix[tgRow].size();
        if (target < matrix[tgRow][0]) return false;
        while (left < right - 1) {
        	mid = (left + right) / 2;
        	if  (target == matrix[tgRow][mid]) return true;
        	else if (target < matrix[tgRow][mid]) {
        		right = mid - 1;
        	}else {
        		left = mid;
        	}
        }
        if (target == matrix[tgRow][right] || target == matrix[tgRow][left]) return true;
        else return false;
    }
};

int main(int argc, char * argv[]) {
	int mat1[2][2] = {{0, 1}, {2, 3}};
	int mat2[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 9}};
	Solution * sol = new Solution();
	vector<vector<int> > matrix1;
	for (int i = 0;i < 2;i++) {
		matrix1.push_back(vector<int>(mat1[i], mat1[i] + sizeof(mat1[i]) / sizeof(int)));
	}
	vector<vector<int> > matrix2;
	for (int i = 0;i < 3;i++) {
		matrix2.push_back(vector<int>(mat2[i], mat2[i] + sizeof(mat2[i]) / sizeof(int)));
	}
	for (int i = -1;i < 5;i++) {
		cout << i << " in matrix1? "<< sol->searchMatrix(matrix1, i) << endl;
	}
	for (int i = -1;i < 11;i++) {
		cout << i << " in matrix2? "<< sol->searchMatrix(matrix2, i) << endl;
	}
	return 0;
}
