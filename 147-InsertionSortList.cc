/**
 * LeetCode Q147 - Insertion Sort List
 * Sort a linked list using insertion sort.
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode * insert;
        ListNode * pseudoHead = new ListNode(0);
        pseudoHead->next = head;
        insert = head->next;
        while(insert != NULL) {
            ListNode * next = insert->next;
            ListNode * iter, * prev;
            bool foundPosition = false;
            iter = pseudoHead->next;prev = pseudoHead;
            while(iter != insert) {
                if (!foundPosition && iter->val > insert->val) {
                    insert->next = iter;
                    prev->next = insert;
                    foundPosition = true;
                    prev = insert;
                }
                iter = iter->next;
                prev = prev->next;
            }
            // If insert Node is insert beforehand
            if (foundPosition) prev->next = next;
            insert = next;
        }
        return pseudoHead->next;
    }
};
