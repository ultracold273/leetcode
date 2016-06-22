/**
 * LeetCode Q110 - Balanced Binary Tree
 * 
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as 
 * a binary tree in which the depth of the two subtrees of every 
 * node never differ by more than 1. 
 */

#include <iostream>
#include <cmath>
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
    bool balancedWithdepth(TreeNode* root, int * depth) {
        if (root == NULL) {
            *depth = 0;
            return true;
        }
        else {
            int dpLeft, dpRight;
            if (balancedWithdepth(root->left, &dpLeft) && balancedWithdepth(root->right, &dpRight)) {
                if (abs(dpLeft - dpRight) <= 1) {
                    *depth = max(dpLeft, dpRight) + 1;
                    return true;
                }
            }
            return false;
        }
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        int depth;
        return balancedWithdepth(root, &depth);
    }
};
