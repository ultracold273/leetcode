/**
 * LeetCode Q113 - Path Sum II
 * Given a binary tree and a sum, find all root-to-leaf paths where 
 * each path's sum equals the given sum.
 * For example:
 * Given the below binary tree and sum = 22,
 *
 *                5
 *               / \
 *              4   8
 *             /   / \
 *            11  13  4
 *           /  \    / \
 *          7    2  5   1
 *
 * return
 * [
 *   [5,4,11,2],
 *   [5,8,4,5]
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
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isLeaf(TreeNode * root) {
        return (root != NULL) && (root->left == NULL) && (root->right == NULL);
    }

    void pathSum_rec(TreeNode * root, int sum, vector<int> &st, vector<vector<int> > &res) {
        if (root == NULL) return ;
        else if (isLeaf(root) && root->val == sum) {
            st.push_back(root->val);
            res.push_back(st);
            st.pop_back();
        }else{
            st.push_back(root->val);
            pathSum_rec(root->left, sum - root->val, st, res);
            pathSum_rec(root->right, sum - root->val, st, res);
            st.pop_back();
        }
    }
    
    vector<vector<int> > pathSum(TreeNode * root, int sum) {
        vector<vector<int> > res;
        if(root == NULL) return res;
        else {
            vector<int> stack;
            pathSum_rec(root, sum, stack, res);
        }
        return res;
    }
};
