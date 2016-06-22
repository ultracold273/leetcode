/**
 * LeetCode Q112 - Path Sum
 * Given a binary tree and a sum, determine if the tree has a 
 * root-to-leaf path such that adding up all the values along the 
 * path equals the given sum.
 * For example:
 * Given the below binary tree and sum = 22,
 *
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \      \
 *         7    2      1
 *
 * return true, as there exist a root-to-leaf path 5->4->11->2 which 
 * sum is 22.
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

    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        else if (isLeaf(root) & root->val == sum) return true;
        else {
            return hasPathSum(root->left, sum - root->val) | hasPathSum(root->right, sum - root->val);
        }
    }
};
