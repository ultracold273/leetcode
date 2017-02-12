/**
 * LeetCode Q144 - Binary Tree Preorder Traversal
 * Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *      \
 *       2
 *      /
 *     3
 * return [1,2,3].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 *  * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode *> st;
		vector<int> result;
		if (root == NULL) return result;
		st.push(root);
		while(!st.empty()) {
			TreeNode * central = st.top();
			st.pop();
			result.push_back(central->val);
			if (central->right != NULL) st.push(central->right);
			if (central->left != NULL) st.push(central->left);
		}
		return result;
	}
};
