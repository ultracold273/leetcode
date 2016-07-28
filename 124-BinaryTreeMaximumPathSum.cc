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

/**
 * Note: the start node does not necessarily be leaf node, it
 * can be any node in the tree.
 */

class Solution {
public:
	int max(int a, int b, int c) {
		if (a > b) {
			return (a > c)?a:c;
		}else{
			return (b > c)?b:c;
		}
	}

	void maxPathSum_rec(TreeNode * root, int * inTree, int * thrTree) {
		int leftInT, leftThrT;
		int rightInT, rightThrT;
		if (root == NULL) {
			*inTree = 0;
			*thrTree = 0;
			return;
		}
		cout << "root->val: " << root->val << endl;
		maxPathSum_rec(root->left, &leftInT, &leftThrT);
		maxPathSum_rec(root->right, &rightInT, &rightThrT);
		*inTree = max(leftInT, rightInT, leftThrT + rightThrT + root->val);
		*thrTree = (leftThrT > rightThrT)?leftThrT:rightThrT + root->val;
	}

    int maxPathSum(TreeNode* root) {
		int inTree, thrTree;
		maxPathSum_rec(root, &inTree, &thrTree);
		return inTree;
    }
};

int main() {
	Solution * sol = new Solution();
	TreeNode r(1);
	TreeNode a(2);
	TreeNode b(3);
	r.left = &a;r.right = &b;
	cout << sol->maxPathSum(&r) << endl;
	return 0;
}
