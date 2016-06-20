/**
 * LeetCode Q108 - Convert Sorted Array to Binary Search Tree
 *
 * Given an array where elements are sorted in ascending order, convert
 * it to a height balanced BST.
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * This question can be done via recursion
 * First find the root, then split the array into two.
 * The first part all belong to its left Tree while the second part
 * all belong to its right tree.
 *
 * A totally balanced BST contains 2^n - 1 elements, If elements
 * are more than this number, the depth of left tree are at most larger 
 * than the depth of right tree plus 1.
 *
 * First find how many elements are there in the left tree and how
 * many are there on the right tree.
 *
 * Either the left tree or the right tree contains the size of 2^n - 1
 * 
 */

/**
 * Defintion for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int ceilinglog2(int x) {
		int log = 0;
		while(x) { x >>= 1; log++; }
		return log;
	}

	int findRoot(int st, int ed) {
		int size = ed - st;
		/*
		if (((size + 1) & size) == 0) return st + size / 2;
		else {
			int log = ceilinglog2(size - 1);
			int leftSize = size - 1 - ((1 << log) - 1);
			int rightSize = size - 1 - leftSize;
			return st + ((leftSize > rightSize)?leftSize:rightSize);
		}
		*/
		return st + size / 2;
	}

	TreeNode * sortedArrayToBST_rec(vector<int> &nums, int st, int ed) {
		if (st == ed) return NULL;
		int rtIndex = findRoot(st, ed);
		TreeNode * root = new TreeNode(nums[rtIndex]);
		TreeNode * leftTree = sortedArrayToBST_rec(nums, st, rtIndex);
		TreeNode * rightTree = sortedArrayToBST_rec(nums, rtIndex + 1, ed);
		root->left = leftTree;
		root->right = rightTree;
		return root;
	}

	TreeNode * sortedArrayToBST(vector<int> &nums) {
		return sortedArrayToBST_rec(nums, 0, nums.size());
	}
};
