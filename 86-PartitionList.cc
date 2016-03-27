/**
 * Leetcode 86 - Partition Lists
 * Given a linked list and a value x, partition it such that all 
 * nodes less than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes 
 * in each of the two partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 */
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode * insert;
        ListNode * search;
        insert = &dummy;
        while(insert->next != NULL && insert->next->val < x) {
            insert = insert->next;
        }
        if (insert->next == NULL) {
            return head;
        }else{
            search = insert;
            while(search->next != NULL) {
                if (search->next->val < x) {
                    ListNode * temp = insert->next;
                    insert->next = search->next;
                    search->next = search->next->next;
                    insert->next->next = temp;
                    insert = insert->next;
                }else{
                    search = search->next;
                }
            }
            return dummy.next;
        }
        
    }
};