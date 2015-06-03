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
		int count = 0;
		ListNode * ptrEd = head;
		ListNode * ptrNewEd = head;
		if(head == NULL || head->next == NULL || k == 0) return head;
		while(ptrEd->next != NULL) count++;
		ptrEd = head;
		int eq_count = k % (count + 1);
		bool endFlag = false;
		while(ptrEd->next != NULL) {
			if (endFlag) ptrNewEd = ptrNewEd->next;
			if (eq_count > 0) {
				count--;
			}else{
				endFlag = true;
			}
			ptrEd = ptrEd->next;			
		}

		if (ptrNewEd->next == NULL)
			return head;
		ptrEd->next = head;
		ptrEd = ptrNewEd->next;
		ptrNewEd->next = NULL;
		return ptrEd;
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
}
