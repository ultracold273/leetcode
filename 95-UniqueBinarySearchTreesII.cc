/**
 * LeetCode Q95 - Unique Binary Search Trees II
 * Given an integer n, generate all structurally unique BST's 
 * (binary search trees) that store values 1...n.
 *
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 *
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode *> generateTrees(int n) {
		vector<TreeNode *> res;
		if (n == 0) return res;
        for (int i = 2;i <= n;i++) {
            
        }
        return res;
	}
};
