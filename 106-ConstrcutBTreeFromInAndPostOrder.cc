/**
 * LeetCode Q106 - Construct Binary Tree From Inorder and Post Order 
 *                 Traversal
 *
 * Given inorder and postorder traversal of a tree, construct the
 * binary tree.
 *
 * Note:
 * You may assume that duplicates do not exitst in the tree.
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
	TreeNode * buildTree_rec(vector<int>& postorder, int * poIdx, vector<int>& inorder, int start, int end) {
		if (start == end) return NULL;
		int rootVal = postorder[*poIdx];
		// Find root in inorder
		int rootFinder = start;
		while(inorder[rootFinder] != rootVal) rootFinder++;
		TreeNode * root = new TreeNode(rootVal);
		(*poIdx)--;
		TreeNode * rightTree = buildTree_rec(postorder, poIdx, inorder, rootFinder + 1, end);
		TreeNode * leftTree = buildTree_rec(postorder, poIdx, inorder, start, rootFinder);
		root->left = leftTree;
		root->right = rightTree;
		return root;
	}

	TreeNode * buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (postorder.size() != inorder.size()) return NULL;
		if (postorder.size() == 0) return NULL;
		int startPoIdx = postorder.size() - 1;
		return buildTree_rec(postorder, &startPoIdx, inorder, 0, inorder.size());
	}
};
