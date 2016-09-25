/**
 * LeetCode Q124 - Binary Tree Maximum Path Sum
 * Given a binary tree, find the maximum path sum.
 *
 * For this problem, a path is defined as any sequence of nodes 
 * from some starting node to any node in the tree along the 
 * parent-child connections. 
 * The path does not need to go through the root.
 *
 * For example:
 * Given the below binary tree,
 *
 *         1
 *        / \
 *       2   3
 *
 * Return 6. 
 */

#include <iostream>
#include <climits>
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
    bool isLeaf(TreeNode * node) {
        return (node != NULL) && (node->left == NULL) && (node->right == NULL);
    }
    
    int maxPathSumThrough(TreeNode * node, int * maxSum) {
        if (isLeaf(node)) {
            if (node->val > *maxSum) 
                *maxSum = node->val;
            return node->val;
        }else if ((node->left != NULL) && (node->right != NULL)) {
            int leftMax = maxPathSumThrough(node->left, maxSum);
            int rightMax = maxPathSumThrough(node->right, maxSum);
            int pSumAll = leftMax + rightMax + node->val;
            int pSumLeft = leftMax + node->val;
            int pSumRight = rightMax + node->val;
            int pSumNode = node->val;

            int maxThree;
            // Get Max from pSumLeft, pSumRight and pSumNode
            if (pSumLeft > pSumRight)
                maxThree = (pSumNode > pSumLeft)?pSumNode:pSumLeft;
            else
                maxThree = (pSumNode > pSumRight)?pSumNode:pSumRight;
            int maxFour;
            // Get max among the four
            maxFour = (maxThree > pSumAll)?maxThree:pSumAll;

            if (maxFour > *maxSum)
                *maxSum = maxFour;
            return maxThree;
        }else {
            if (node->left != NULL) {
                int leftMax = maxPathSumThrough(node->left, maxSum);
                int maxPath = (leftMax > 0)?(leftMax + node->val):node->val;
                if (maxPath > *maxSum) {
                    *maxSum = maxPath;
                }
                return maxPath;
            } else {
                int rightMax = maxPathSumThrough(node->right, maxSum);
                int maxPath = (rightMax > 0)?(rightMax + node->val):node->val;
                if (maxPath > *maxSum) {
                    *maxSum = maxPath;
                }
                return maxPath;
            }
        }
    }

    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        if (root == NULL) return 0;
        int throughRoot = maxPathSumThrough(root, &res);
        if (res > throughRoot)
            return res;
        else 
            return throughRoot;
    }
};

int main() {
    TreeNode a(-1), b(2);
    b.left = &a;
    Solution *sol = new Solution();
    cout << sol->maxPathSum(&b) << endl;
    return 0;
}
