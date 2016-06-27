/**
 * LeetCode Q129 - Sum Root to Leaf Numbers
 * Given a binary tree containing digits from 0-9 only, each 
 * root-to-leaf path could represent a number.
 *
 * An example is the root-to-leaf path 1->2->3 which represents the 
 * number 123.
 *
 * Find the total sum of all root-to-leaf numbers.
 *
 * For example,
 *
 *     1
 *    / \
 *   2   3
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 *
 * Return the sum = 12 + 13 = 25.
 */

#include <iostream>
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
	bool isLeaf(TreeNode* root) {
		return (root != NULL) && (root->left == NULL) && (root->right == NULL);
	}
	void sumNumbers_rec(TreeNode* root, int *sum, int* pathSum) {
		if (root == NULL) return;
		else if (isLeaf(root)) {
			*pathSum = ((*pathSum) * 10) + root->val;
			*sum += *pathSum;
			*pathSum /= 10;
		}else{
			*pathSum = (*pathSum) * 10 + root->val;
			sumNumbers_rec(root->left, sum, pathSum);
			sumNumbers_rec(root->right, sum, pathSum);
			*pathSum /= 10;
		}
	}
	int sumNumbers(TreeNode* root) {
		int sum = 0;
		int pathSum = 0;
		sumNumbers_rec(root, &sum, &pathSum);
		return sum;
	}
};
