/**
 * LeetCode Q160 - Intersection of Two Linked Lists
 * Write a program to find the node at which the intersection of two 
 * singly linked lists begins.
 *
 * For example, the following two linked lists:
 *
 * A:          a1 -> a2
 *
 *                       c1 -> c2 -> c3
 *
 * B:     b1 -> b2 -> b3
 *
 * begin to intersect at node c1.
 *
 * Notes:
 *
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the 
 * function returns.
 * You may assume there are no cycles anywhere in the entire linked 
 * structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 *
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int aLength, bLength;
        ListNode * iterA, * iterB;
        iterA = headA;aLength = 0;
        iterB = headB;bLength = 0;
        if (headA == NULL || headB == NULL) return NULL;
        while(iterA->next != NULL) {
            iterA = iterA->next;
            aLength++;
        }
        while(iterB->next != NULL) {
            iterB = iterB->next;
            bLength++;
        }
        // If last node is not the same, they have no intersection
        if (iterA != iterB) {
            return NULL;
        }
        // Start from the same length
        iterA = headA;iterB = headB;
        if (aLength > bLength) {
            while(aLength-- != bLength) iterA = iterA->next;
        }else{
            while(bLength-- != aLength) iterB = iterB->next;
        }
        // Move one by one after to see whether they are the same
        while(iterA != iterB) {
            iterA = iterA->next;
            iterB = iterB->next;
        }
        return iterA;
    }
};
