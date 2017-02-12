/**
 * LeetCode Q142 - Linked List Cycle II
 * Given a linked list, return the node where the cycle begins. 
 * If there is no cycle, return null.
 *
 * Note: Do not modify the linked list.
 *
 * Follow up:
 * Can you solve it without using extra space?
 */

#include <iostream>
using namespace std;
/**
 *  * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode * fast;
		ListNode * slow;
		bool hasLoop = false;
		if (head == NULL) return NULL;
		fast = slow = head;
		while(fast->next != NULL && fast->next->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) {
				hasLoop = true;
				break;
			}
		}
		if (hasLoop) {
			int count = 0;
			do {
				fast = fast->next->next;
				slow = slow->next;
				count++;
			}while(fast != slow);
			// count means the loop length
			fast = slow = head;
			while(count--) {
				fast = fast->next;
			}
			while(fast != slow) {
				fast = fast->next;
				slow = slow->next;
			}
			return slow;
		}else return NULL;
	}
};
