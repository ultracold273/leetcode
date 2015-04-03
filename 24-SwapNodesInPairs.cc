/**
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * Your algorithm should use only constant space. You may not modify the 
 * values in the list, only nodes itself can be changed.
 */

 /**
 * Definition for singly-linked list.
 */
 #include <iostream>
 using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 void printf_List(ListNode * head) {
	while(head != NULL) {
		cout << head->val << ' ';
		head = head->next;
	}
	cout << endl;
 }

 class Solution {
 public:
     ListNode *swapPairs(ListNode *head) {
     	if (head == NULL || head->next == NULL) return head;
     	ListNode * lnOdd, * lnEven, * prev, * newhead;
     	int termination = 0;
     	prev = NULL;
     	lnOdd = head;
     	lnEven = head->next;
     	newhead = lnEven;
     	do {
     		if (lnEven->next == NULL) termination = 1;
     		lnOdd->next = lnEven->next;
     		lnEven->next = lnOdd;
     		if (prev != NULL) prev->next = lnEven;
     		//cout << lnOdd->val << ' ' << lnEven->val << endl;
     		if (termination == 0) {
     			prev = lnOdd;
     			lnOdd = lnOdd->next;
     			if(lnOdd->next == NULL) termination = 1;
     			else lnEven = lnOdd->next; 
     		}
     	}while(!termination);
     	return newhead;
     }
 };

 int main(int argc, char const *argv[])
 {
 	Solution * sol = new Solution();
 	ListNode a(1);
 	ListNode b(2);
 	ListNode c(3);
 	ListNode d(4);
 	a.next = &b;b.next = &c;c.next = &d;
 	ListNode * res = sol->swapPairs(&a);
 	printf_List(res);
 	return 0;
 }