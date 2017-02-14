/**
 * LeetCode Q141 - Linked List Cycle
 * Given a linked list, determine if it has a cycle in it.
 *
 * Follow up:
 * Can you solve it without using extra space? 
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
 
/* 
 * This modifies the original list
 * Typical use runner and walker algorithms.
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * iter = head;
        ListNode * next;
        while(iter != NULL) {
            if(iter->next == NULL) {
                return false;
            }else if (iter->next == head) {
                return true;
            }
            next = iter->next;
            iter->next = head;
            iter = next;
        }
        return false;
    }
};
