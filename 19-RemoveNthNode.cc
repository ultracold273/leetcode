/**
 * Given a linked list, 
 * remove the nth node from the end of list \
 * and return its head.
 * For example,
 *  Given linked list: 1->2->3->4->5, 
 *  and n = 2.
 *  After removing the second node from the 
 *  end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass. 
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *prev = NULL;
    	ListNode *curr = head;
    	while(1) {
    		ListNode *reach = curr;
    		for (int i = 1; i < n; ++i)
    		{
    			reach = reach->next;
    		}
    		if (reach->next == NULL) {
    			// We found it
    			if (prev != NULL) prev->next = curr->next;
    			else head = curr->next;
    			free(curr);
    			return head;
    		}
    		prev = curr;
    		curr = curr->next;
    	}
    }
};