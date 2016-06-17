/**
 * LeetCode Q101 - Symmetric Tree
 * Given a binary tree, check whether it is a mirror of itself 
 * (ie, symmetric around its center).
 *
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 *
 * But the following [1,2,2,null,3,null,3] is not:
 *
 *     1
 *    / \
 *   2   2
 *    \   \
 *     3   3
 *
 * Note:
 * Bonus points if you could solve it both recursively and iteratively. 
 */

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
    bool isSubTreeSymmetric(TreeNode* treeLeft, TreeNode* treeRight) {
        if (treeLeft == NULL && treeRight == NULL) return true;
        if (treeLeft != NULL && treeRight != NULL) {
            if (treeLeft->val != treeRight->val) return false;
            if (isSubTreeSymmetric(treeLeft->left, treeRight->right) && isSubTreeSymmetric(treeLeft->right, treeRight->left)) {
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return isSubTreeSymmetric(root->left, root->right);
    }
};
