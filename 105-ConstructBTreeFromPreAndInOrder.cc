/**
 * LeetCode Q105 - Construct Binary Tree From Preorder and Inorder Traversal
 * Given preorder and inorder traversal of a tree, construct the binary 
 * tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Preorder Traversal: Recursively defined visit root, leftTree, rightTree
 * Inorder Traversal: Recursively defined visit leftTree, root, rightTree
 * The first element in preorder is the root of all node, find the same
 * one in inorder, suppose it is in i-th position. Then all elements from
 * position 0 to i-1 shall be in the left tree. All elements from i+1 to 
 * the final shall be in the right tree. We can build the tree in a 
 * recursive way.
 */


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
	TreeNode * buildTree_rec(vector<int>& preorder, int * poIdx, vector<int>& inorder, int start, int end) {
		if (start == end) return NULL;
		int rootVal = preorder[*poIdx];
		// Find root in inorder
		int rootFinder = start;
		while(inorder[rootFinder] != rootVal) rootFinder++;
		TreeNode * root = new TreeNode(rootVal);
		(*poIdx)++;
		TreeNode * leftTree = buildTree_rec(preorder, poIdx, inorder, start, rootFinder);
		TreeNode * rightTree = buildTree_rec(preorder, poIdx, inorder, rootFinder + 1, end);
		root->left = leftTree;
		root->right = rightTree;
		return root;
	}

	TreeNode * buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() != inorder.size()) return NULL;
		if (preorder.size() == 0) return NULL;
		int startPoIdx = 0;
		return buildTree_rec(preorder, &startPoIdx, inorder, 0, inorder.size());
	}
};
