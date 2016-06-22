/**
 * LeetCode Q114 - Flatten Binary Tree to Linked List
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example,
 * Given
 *           1
 *          / \
 *         2   5
 *        / \   \
 *       3   4   6
 *
 * The flattened tree should look like:
 *
 *      1
 *       \
 *        2
 *         \
 *          3
 *           \
 *            4
 *             \
 *              5
 *               \
 *                6
 *
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
    bool isLeaf(TreeNode * root) {
        return (root != NULL) && (root->left == NULL) && (root->right == NULL);
    }

    TreeNode *flattenReturnTail_rec(TreeNode * root) {
        if (root == NULL) return NULL;
        else if (isLeaf(root)) return root;
        else {
            TreeNode *lfTail = flattenReturnTail_rec(root->left);
            TreeNode *rtTail = flattenReturnTail_rec(root->right);
            if (lfTail != NULL) {
                lfTail->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            return (rtTail == NULL)?lfTail:rtTail;
        }
    }

    void flatten(TreeNode * root) {
        flattenReturnTail_rec(root);
    }
};

int main() {
    TreeNode root(1);
    TreeNode leftT(2);
    root.left = &leftT;
    Solution * sol = new Solution();
    sol->flatten(&root);
    cout << root.right->val << endl;
}
