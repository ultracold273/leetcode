/**
 * LeetCode Q148 - Sort List
 * Sort a linked list in O(n log n) time using constant space complexity.
 */

#include <iostream>
using namespace std;

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
// Heap Sort
    ListNode* mergeSortedList(ListNode* head1, ListNode* head2) {
        ListNode * head, * iter_main, * iter_other;
        if (head1 == NULL) {
            return head2;
        }else if (head2 == NULL) {
            return head1;
        }
        if (head1->val < head2->val) {
            head = head1;
            iter_main = head1;iter_other = head2;
        }else{
            head = head2;
            iter_main = head2;iter_other = head1;
        }
        ListNode * iter_main_prev = iter_main;
        while(iter_main != NULL && iter_other != NULL) {
            if (iter_other->val < iter_main->val) {
                ListNode * next_iter_other = iter_other->next;
                iter_main_prev->next = iter_other;
                iter_other->next = iter_main;
                iter_main_prev = iter_other;
                iter_other = next_iter_other;
            }else{
                iter_main_prev = iter_main;
                iter_main = iter_main->next;
            }
        }
        if (iter_main == NULL) {
            iter_main_prev->next = iter_other;
        }
        return head;
    }
    
    ListNode* sortList_rec(ListNode* head, int length) {
        if (head == NULL) return NULL;
        else if (head->next == NULL) return head;
        ListNode * iter;
        iter = head;
        int mpos = length / 2;
        while(--mpos) iter = iter->next;
        ListNode * left = head;
        ListNode * right = iter->next;
        iter->next = NULL;
        left = sortList_rec(left, length / 2);
        right = sortList_rec(right, length - length / 2);
        return mergeSortedList(left, right);
    }
    
    ListNode* sortList(ListNode* head) {
        if (head == NULL) return NULL;
        else if (head->next == NULL) return head;
        int listLength = 0;
        ListNode * iter;
        iter = head;
        while(iter != NULL) {
            listLength++;
            iter = iter->next;
        }
        return sortList_rec(head, listLength);
    }
};
