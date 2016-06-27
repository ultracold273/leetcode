/**
 * LeetCode Q99 - Recover Binary Search Tree
 * Two elements of a binary search tree (BST) are swapped by mistake.
 *
 * Recover the tree without changing its structure.
 *
 * Note:
 * A solution using O(n) space is pretty straight forward. 
 * Could you devise a constant space solution?
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
	TreeNode(int n) : val(n), left(NULL), right(NULL) {}
};

class Solution {
public:
	void validateNode(TreeNode * root, int lBound, int uBound, bool intMin, bool intMax, vector<TreeNode *> &res, vector<int> &dir) {
		if (root->val == INT_MIN) intMin = false;
		if (root->val == INT_MAX) intMax = false;
		if (root->left != NULL) {
			int leftVal = root->left->val;
			if (leftVal >= root->val || leftVal <= lBound) {
				if (leftVal == INT_MIN && lBound == INT_MIN && intMin) {}
				else {res.push_back(root);dir.push_back(0);}
			}else{
				validateNode(root->left, lBound, root->val, intMin, intMax, res, dir);
			}
		}
		if (root->right != NULL) {
			int rightVal = root->right->val;
			if (rightVal <= root->val || rightVal >= uBound) {
				if (rightVal == INT_MAX && uBound == INT_MAX && intMax) {}
				else {res.push_back(root);dir.push_back(1);}
			}else{
				validateNode(root->right, root->val, uBound, intMin, intMax, res, dir);
			}
		}
	}
	void recoverTree(TreeNode * root) {
		if (root == NULL) return;
		vector<TreeNode *> badTreeNode;
		vector<int> direction;
		validateNode(root, INT_MIN, INT_MAX, true, true, badTreeNode, direction);
		if (badTreeNode.size() == 1) {
			TreeNode * tRoot = badTreeNode[0];
			TreeNode * badNode;
			if (direction[0] == 0) {
				badNode = tRoot->left;
				tRoot->left = NULL;
			}else {
				badNode = tRoot->right;
				tRoot->right = NULL;
			}
			TreeNode * newNode = Search(badNode->val);

		}else if (badTreeNode.size() == 2){
			TreeNode * tRoot1 = badTreeNode[0];
			TreeNode * tRoot2 = badTreeNode[1];
			TreeNode * temp;
			if (direction[0] == 0 && direction[1] == 0) {
				temp = tRoot1->left;
				tRoot1->left = tRoot2->left;
				tRoot2->left = temp;
			}else if (direction[0] == 0 && direction[1] == 1) {
				temp = tRoot1->left;
				tRoot1->left = tRoot2->right;
				tRoot2->right = temp;
			}else if (direction[0] == 1 && direction[1] == 0) {
				temp = tRoot1->right;
				tRoot1->right = tRoot2->left;
				tRoot2->left = temp;
			}else if (direction[0] == 1 && direction[1] == 1) {
				temp = tRoot1->right;
				tRoot1->right = tRoot2->right;
				tRoot2->right = temp;
			}
		}
	}
};
