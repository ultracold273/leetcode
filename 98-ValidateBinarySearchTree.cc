/**
 * LeetCode Q98 - Validate Binary Search Tree
 * Given a binary tree, determine if it is a valid binary search tree 
 * (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * The left subtree of a node contains only nodes with keys less 
 * than the node's key.
 * The right subtree of a node contains only nodes with keys greater 
 * than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * Example 1:
 *     2
 *    / \
 *   1   3
 * Binary tree [2,1,3], return true.
 * Example 2:
 *     1
 *    / \
 *   2   3
 * Binary tree [1,2,3], return false.
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
    bool isValidTree(TreeNode * root, int leftVal, int rightVal, bool minIntPermit, bool maxIntPermit) {
        if (root == NULL) return true;
        if (root->val <= leftVal) {
            if (root->val == INT_MIN && leftVal == root->val) {
                if (!minIntPermit) return false;
                minIntPermit = false;
            }else {
                return false;
            }
        }
        if (root->val >= rightVal) {
            if (root->val == INT_MAX && rightVal == root->val) {
                if (!maxIntPermit) return false;
                maxIntPermit = false;
            }else {
                return false;
            }
        }
        if (root->left != NULL) {
            if (!isValidTree(root->left, leftVal, root->val, minIntPermit, maxIntPermit)) return false;
        }
        if (root->right != NULL) {
            if (!isValidTree(root->right, root->val, rightVal, minIntPermit, maxIntPermit)) return false;
        }
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        bool minIntPermit = (root->val == INT_MIN)?false:true;
        bool maxIntPermit = (root->val == INT_MAX)?false:true;
        if (isValidTree(root->left, INT_MIN, root->val, minIntPermit, maxIntPermit) && 
            isValidTree(root->right, root->val, INT_MAX, minIntPermit, maxIntPermit)) 
            return true;
        else return false;
    }
};