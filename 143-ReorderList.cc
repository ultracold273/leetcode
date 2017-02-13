/**
 * LeetCode Q143 - Reorder List
 * Given a singly linked list L: L0->L1->...->Ln-1->Ln,
 * reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->...
 *
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 *
 */

#include <iostream>
using namespace std;

/**
 *  * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode* head) {
		int listLength = 0;
		ListNode * iter;
		if (head == NULL) return ;
		iter = head;
		while(iter != NULL) {
			iter = iter->next;
			listLength++;
		}
		// Find the mid Point of the list
		iter = head;
		int midIndex = listLength / 2 + 1;
		// 1 -> 2 -> 3 -> 4 => 1 -> 2 -> 3 <- 4
		while(--midIndex) {
			iter = iter->next;
		}
		ListNode * next = iter->next;
		iter->next = NULL;
		while(next != NULL) {
			ListNode * temp = next->next;
			next->next = iter;
			iter = next;
			next = temp;
		}
		// Exchange the sequence alternatively
		ListNode * back = iter;
		iter = head;
		while(iter != back && back->next != NULL) {
			ListNode * iterN, * backN;
			iterN = iter->next;
			backN = back->next;
			iter->next = back;
			back->next = iterN;
			iter = iterN;
			back = backN;
		}
		return ;
	}
};
