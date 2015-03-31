/**
 * Merge two sorted linked lists and return
 * it as a new list.
 * The new list should be made by splicing
 * together the nodes of the first two lists.
 *
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode * dummy = new ListNode(0);
		ListNode * current = dummy;
		while(l1 != NULL && l2 != NULL) {
			if(l1->val < l2->val) {
				current->next = new ListNode(l1->val);
				current = current->next;
				l1 = l1->next;
			}else {
				current->next = new ListNode(l2->val);
				current = current->next;
				l2 = l2->next;
			}
		}

		if(l1 != NULL) {
			while(l1 != NULL) {
				current->next = new ListNode(l1->val);
				current = current->next;
				l1 = l1->next;
			}
		}else {
			while(l2 != NULL) {
				current->next = new ListNode(l2->val);
				current = current->next;
				l2 = l2->next;
			}
		}
		return dummy->next;
	}
};