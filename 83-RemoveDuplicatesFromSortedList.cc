/**
 * Given a sorted linked list, delete all duplicates such 
 * that each element appear only once.
 * 
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * curr = head;
        ListNode * prev = head;
        if (head == NULL || head->next == NULL) return head;
        curr = curr->next;
        bool isStartDuplicate = false;
        while(curr != NULL) {
            if (curr->val == prev->val) {
                if (!isStartDuplicate) {
                    isStartDuplicate = true;
                }
            }else{
                if (isStartDuplicate) {
                    isStartDuplicate = false;
                    prev->next = curr;
                }
            }
            if (!isStartDuplicate)
                prev = curr;
            curr = curr->next;
        }
        if (isStartDuplicate) {
            prev->next = NULL;
        }
        return head;
    }
};