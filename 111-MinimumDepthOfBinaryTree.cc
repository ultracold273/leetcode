/**
 * LeetCode Q111 - Minimum Depth of Binary Tree
 * Given a binary tree, find its minimum depth.

 * The minimum depth is the number of nodes along the shortest path from the root
 * node down to the nearest leaf node.
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
    bool isLeaf(TreeNode* root) {
        return (root != NULL) && (root->left == NULL) && (root->right == NULL);
    }
    
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        else if (isLeaf(root)) return 1;
        else {
            int leftMin = (root->left == NULL) ? INT_MAX : minDepth(root->left);
            int rightMin = (root->right == NULL) ? INT_MAX : minDepth(root->right);
            return min(leftMin, rightMin) + 1;
        }
    }
};