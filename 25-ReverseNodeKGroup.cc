/**
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 * 
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 * 
 * You may not alter the values in the nodes, only nodes itself may be changed.
 * 
 * Only constant memory is allowed.
 * 
 * For example,
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
 */
 /**
 * Definition for singly-linked list.
 */

 /**
  * This method is a little bit too slow 2n complexity, if we can reverse the node while counting
  * the code may be more efficient.
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
    ListNode *reverseKGroup(ListNode *head, int k) {
    	// Deal with corner cases
    	if (head == NULL || head->next == NULL || k == 1) return head;
    	ListNode * start, * end, * prev, * newhead;
    	prev = NULL;
    	start = head;
    	end = start;
    	newhead = head;
        int termination = 0;
        do {
        	for(int i = 0;i < k - 1;i++) {
        		if(end->next == NULL) {
        			return newhead;
        		}
        		end = end->next;
        	}
            if (end->next == NULL) termination = 1;
        	reverseOnList(start, end);
            // If we have succesfully reverse k node once, we update the newhead to be returned
            if (newhead == head) newhead = end;
            if (prev != NULL) prev->next = end; 
            prev = start;
            if(!termination) {
                start = start->next;
                end = start;
            }
        }while(!termination);
        return newhead;
    }

    void reverseOnList(ListNode * st, ListNode * end) {
    	ListNode * prev, * next;
        prev = st;
        next = st->next;
        while(next != end) {
            ListNode * temp;
            temp = next->next;
            next->next = prev;
            prev = next;
            next = temp;
        }
        st->next = end->next;
        end->next = prev;
    }
};

int main(int argc, char const *argv[])
{
	Solution * sol = new Solution();
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;b.next = &c;c.next = &d;d.next = &e;
    ListNode * res = sol->reverseKGroup(&a, 2);
    printf_List(res);
	return 0;
}