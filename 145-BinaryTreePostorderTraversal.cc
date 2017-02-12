/**
 * LeetCode Q145 - Binary Tree Postorder Traversal
 * Given a binary tree, return the postorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *      \
 *       2
 *      /
 *     3
 * return [3, 2, 1].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 */

#include <iostream>
#include <algorithm>
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
		// Reverse of central, right, left
		stack<TreeNode *> st;
		vector<int> result;
		if (root == NULL) return result;
		st.push(root);
		while(!st.empty()) {
			TreeNode * central = st.top();
			st.pop();
			result.push_back(central->val);
			if (central->left != NULL) st.push(central->left);
			if (central->right != NULL) st.push(central->right);
		}
		reverse(result.begin(), result.end());
		return result;
	}
};
