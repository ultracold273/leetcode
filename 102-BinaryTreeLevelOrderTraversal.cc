/**
 * LeetCode Q102 - Binary Tree Level Order Traversal
 * Given a binary tree, return the level order traversal of its nodes' 
 * values. (ie, from left to right, level by level).
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 * return its level order traversal as:
 *
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if (root == NULL) return res;
        queue<TreeNode *> * qLevel = new queue<TreeNode *>();
        queue<TreeNode *> * qNextLevel = new queue<TreeNode *>();
        vector<int> * levelVal = new vector<int>();
        qLevel->push(root);
        while(!qLevel->empty()) {
            TreeNode * tNode = qLevel->front();
            levelVal->push_back(tNode->val);
            if (tNode->left != NULL) qNextLevel->push(tNode->left);
            if (tNode->right != NULL) qNextLevel->push(tNode->right);
            qLevel->pop();
            if (qLevel->empty()) {
                queue<TreeNode *> * temp;
                res.push_back(*levelVal);
                temp = qLevel;
                qLevel = qNextLevel;
                qNextLevel = temp;
                delete levelVal;
                levelVal = new vector<int>();
            }
        }
        return res;
    }
};
