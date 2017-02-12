/**
 * LeetCode Q138 - Copy List with Random Pointer
 * A linked list is given such that each node contains an additional random 
 * pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 */

#include <iostream>
using namespace std;
/**
 *Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

/**
 * There are two ways to solve this problem
 * Intuitive one use a hash map store the address pair with original
 * and duplicated nodes, which takes additional N memory space
 * Another modifies the original list by connecting the duplicated node
 * with original one, so that no extra space is required.
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode * iter;
        RandomListNode * next;
        if (head == NULL) return NULL;
        // First duplicated a list and combine it with original one
        // Orig  #0 -> dup #0 -> orig #1 -> dup #1 -> ...
        iter = head;
        while(iter != NULL) {
            RandomListNode * dupNode = new RandomListNode(iter->label);
            next = iter->next;
            dupNode->next = next;
            iter->next = dupNode;
            iter = next;
        }
        // Connect random pointer
        iter = head;
        while(iter != NULL) {
            RandomListNode * dupNode;
            dupNode = iter->next;
            dupNode->random = (iter->random == NULL)? NULL: iter->random->next;
            iter = iter->next->next;
        }
        // Restore both linked list
        iter = head;
        RandomListNode * dupHead = head->next;
        while(iter != NULL) {
            RandomListNode * dupNode;
            dupNode = iter->next;
            iter->next = dupNode->next;
            dupNode->next = (dupNode->next == NULL) ? NULL : dupNode->next->next;
            iter = iter->next;
        }
        return dupHead;
    }};
