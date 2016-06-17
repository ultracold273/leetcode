/**
 * LeetCode Q103 - Binary Tree Zigzag Level Order Traversal
 * Given a binary tree, return the zigzag level order traversal of 
 * its nodes' values. (ie, from left to right, then right to left 
 * for the next level and alternate between).
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
 * return its zigzag level order traversal as:
 *
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 */

#include <iostream>
#include <vector>
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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if (root == NULL) return res;
        bool reverse = false;
        vector<TreeNode *> * vLevel = new vector<TreeNode *>();
        vector<TreeNode *> * vLevelReverse = new vector<TreeNode *>();
        vector<int> * levelVal = new vector<int>();
        vLevel->push_back(root);
        while((!reverse & !vLevel->empty()) || (reverse & !vLevelReverse->empty())) {
            TreeNode * tNode = (reverse)?vLevelReverse->back():vLevel->front();
            levelVal->push_back(tNode->val);
            if (reverse) {
                if (tNode->right != NULL) vLevel->insert(vLevel->begin(), tNode->right);
                if (tNode->left != NULL) vLevel->insert(vLevel->begin(), tNode->left);
                vLevelReverse->pop_back();
            }else {
                if (tNode->left != NULL) vLevelReverse->push_back(tNode->left);
                if (tNode->right != NULL) vLevelReverse->push_back(tNode->right);
                vLevel->erase(vLevel->begin());
            }
            
            if ((reverse & vLevelReverse->empty()) || (!reverse & vLevel->empty())) {
                res.push_back(*levelVal);
                delete levelVal;
                levelVal = new vector<int>();
                reverse = !reverse;
            }
        }
        return res;
    }
};
