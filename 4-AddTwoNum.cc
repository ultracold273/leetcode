/**
 * Leetcode Question 4
 * Description:
 * You are given two linked lists representing 
 * two non-negative numbers. 
 * The digits are stored in reverse order and 
 * each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * End Date: Dec. 19, 2014
 */

#include <stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) {
		val = x;
		next = NULL;
	}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode * lnPtr, * head_dummy, * prev;
        head_dummy = prev = new ListNode(0);
        int carry = 0;
		int haul_flag_1 = 0, haul_flag_2 = 0;
        while (haul_flag_1 != 1 || haul_flag_2 != 1) {
			int l1val = haul_flag_1?0:l1->val;
			int l2val = haul_flag_2?0:l2->val;
            lnPtr = new ListNode((l1val + l2val + carry) % 10);
            carry =  (l1val + l2val + carry)/10;
            prev->next = lnPtr;
            prev = lnPtr;
			if (l1->next == NULL) {
				haul_flag_1 = 1;
			}else
				l1 = l1->next;
			if (l2->next == NULL) {
				haul_flag_2 = 1;
			}else 
				l2 = l2->next;
        }
		if (carry == 1) {
			lnPtr = new ListNode(1);
			prev->next = lnPtr;
		}
        return head_dummy->next;
    }
};

int main() {
//	ListNode * a = new ListNode()
	return 0;
}
