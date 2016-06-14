/**
 * LeetCode Q94 - Binary Tree Inorder Traversal
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree [1,null,2,3],
 *    1
 *      \
 *        2
 *       /
 *      3
 * return [1,3,2].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void inorderTraversal_rec(TreeNode *root, vector<int> & res) {
        if (root == NULL) return;
		if (root->left != NULL) {
			inorderTraversal_rec(root->left, res);
		}
		res.push_back(root->val);
		if (root->right != NULL) {
			inorderTraversal_rec(root->right, res);
		}
	}

	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> res;
		inorderTraversal_rec(root, res);
		return res;
	}
};
