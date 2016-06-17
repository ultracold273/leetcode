/**
 * LeetCode Q104 - Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode* root) {
        int leftMaxDepth = 0;
        int rightMaxDepth = 0;
        if (root == NULL) return 0;
        if (root->left != NULL) leftMaxDepth = maxDepth(root->left);
        if (root->right != NULL) rightMaxDepth = maxDepth(root->right);
        return max(leftMaxDepth, rightMaxDepth) + 1;
    }
};
