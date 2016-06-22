/**
 * LeetCode Q109 - Convert Sorted List to Binary Search Tree
 *
 * Given a singly linked list where elements are sorted in ascending
 * order, convert it to a height balanced BST.
 */

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for a binary tree node
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
		int size = 0;
		ListNode * ptr = head;
		ListNode * dummy = new ListNode(-1);
		int pos;
		while(ptr != NULL) {size++;ptr = ptr->next;}
		if (size == 0) return NULL;
		else if (size % 2 == 1) pos = size / 2 + 1;
		else pos = size / 2;
		//cout << "size: " << size << " pos: " << pos << endl;
		ptr = head;
		ListNode * prev = dummy;
		while(--pos > 0) {
			prev = ptr;
			ptr = ptr->next;
		}
		TreeNode * root = new TreeNode(ptr->val);
		TreeNode * rightTree = sortedListToBST(ptr->next);
		if (prev == dummy) head = NULL;
		else prev->next = NULL;
		//cout << "root: " << root->val << endl;
		//cout << "head == NULL: " << (head == NULL) << endl; 
		TreeNode * leftTree = sortedListToBST(head);
		root->left = leftTree;
		root->right = rightTree;
		return root;
    }
};

int main() {
	ListNode * head = new ListNode(1);
	ListNode * one = new ListNode(2);
	ListNode * two = new ListNode(3);
	head->next = one;one->next = two;
	Solution * sol = new Solution();
	TreeNode * trNode = sol->sortedListToBST(head);
	cout << trNode->val << endl;
	cout << trNode->right->val << endl;
	cout << trNode->left->val << endl;
}
