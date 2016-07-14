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
	TreeLinkNode * findLeftNodeInNextLevel(TreeLinkNode * inNode) {
		while(inNode != NULL && inNode->left == NULL && inNode->right == NULL) {
			inNode = inNode->next;
		}
		return (inNode == NULL)?NULL:((inNode->left != NULL)?inNode->left:inNode->right);
	}

	TreeLinkNode * findRightNodeInNextLevel(TreeLinkNode * leftHead) {
		if (leftHead == NULL) return NULL;
		while(leftHead->next != NULL) leftHead = leftHead->next;
		return leftHead;
	}

	TreeLinkNode * findNextLeftHeadInNextLevel(TreeLinkNode * leftHead) {
		while(leftHead != NULL && leftHead->left == NULL && leftHead->right == NULL) {
			leftHead = leftHead->next;
		}
		return (leftHead == NULL)?NULL:((leftHead->left != NULL)?leftHead->left:leftHead->right);
	}

    void connect(TreeLinkNode *root) {
		if (root == NULL) return;
		connect(root->left);
		connect(root->right);
		TreeLinkNode * rightAtLeft = root->left;
		TreeLinkNode * leftHead = root->left;
		TreeLinkNode * leftAtRight = root->right;
		while(rightAtLeft != NULL) {
			rightAtLeft->next = leftAtRight;
			leftHead = findLeftNodeInNextLevel(leftHead);
//			rightAtLeft = rightAtLeft->right;
			rightAtLeft = findRightNodeInNextLevel(leftHead);
			leftAtRight = findLeftNodeInNextLevel(leftAtRight);
		}
    }
};
