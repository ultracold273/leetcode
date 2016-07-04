/**
 * LeetCode 117 - Populating Next Right Pointers in Each Node II
 *
 * Follow up for problem "Popluating Next Right Pointers in Each Node".
 *
 * What if the given tree could be any binary tree? Would you previous
 * solution still work?
 *
 * Note:
 * You may only use constant extra space.
 *
 * For example,
 * Given the following perfect binary tree,
 *
 *     1
 *    /  \
 *   2    3
 *  / \    \
 * 4   5    7
 *
 * After calling your function, the tree should look like:
 *
 *      1 -> NULL
 *     /  \
 *    2 -> 3 -> NULL
 *   / \    \
 *  4-> 5 -> 7 -> NULL
 *
 */

#include <iostream>
using namespace std;

/**
 * Definition for binary tree with next pointer.
 */

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
		if (root == NULL) return;
		connect(root->left);
		connect(root->right);
		TreeLinkNode * rightAtLeft = root->left;
		TreeLinkNode * leftAtRight = root->right;
		while(rightAtLeft != NULL) {
			rightAtLeft->next = leftAtRight;
			rightAtLeft = rightAtLeft->right;
			leftAtRight = leftAtRight->left;
		}
    }
};
