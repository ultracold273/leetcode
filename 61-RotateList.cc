/**
 * Given a list, rotate the list to the right by k places, 
 * where k is non-negative.
 *
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 */

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * rotateRight(ListNode * head, int k) {
		int count = 1;
		if(head == NULL || head->next == NULL || k == 0) return head;
		ListNode * ptrEd = head;
		while(ptrEd->next != NULL) {
			ptrEd = ptrEd->next;
			count++;
		}
		ptrEd->next = head;
		k = count - k % count;
		for (int i = 0;i < k;i++) {
			ptrEd = ptrEd->next;
		}

		head = ptrEd->next;
		ptrEd->next = NULL;

		return head;
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
}
