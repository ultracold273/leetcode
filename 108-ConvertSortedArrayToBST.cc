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
 * Determine the depth of the total tree
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
	TreeNode * sortedArrayToBST(vector<int> &nums) {
	}
};
