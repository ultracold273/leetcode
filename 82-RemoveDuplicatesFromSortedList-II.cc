/**
 * Given a sorted linked list, delete all nodes that have 
 * duplicate numbers, leaving only distinct numbers from the 
 * original list.
 * 
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * prev = head;
        ListNode * curr = head;
        bool isCurrDuplicated = false;
        ListNode * dupPrev;
        if (head == NULL || head->next == NULL) return head;
        while(curr->next != NULL && curr != NULL) {
            if (curr->val == curr->next->val) {
                // Duplication detected!
                if (!isCurrDuplicated) {
                    isCurrDuplicated = true;
                    dupPrev = prev;
                }
            }else{
                // Duplciation ended!
                if (isCurrDuplicated) {
                    isCurrDuplicated = false;
                    // Cut Duplicate (dupPrev, curr)
                    if (dupPrev == head && dupPrev->val == dupPrev->next->val) {
                        // Duplication starts from head
                        head = curr->next;
                        curr = head;
                        prev = head;
                    }else{
                        dupPrev->next = curr->next;
                        prev = dupPrev;
                        curr = curr->next;
                    }
                    continue;
                }
                
            }
            prev = curr;
            curr = curr->next;
        }
        if (isCurrDuplicated) {
            isCurrDuplicated = false;
            // Cut Duplicate (dupPrev, curr)
            if (dupPrev == head && dupPrev->val == dupPrev->next->val) {
                // Duplication starts from head
                head = curr->next;
                curr = head;
                prev = head;
            }else{
                dupPrev->next = curr->next;
                prev = dupPrev;
                curr = curr->next;
            }
        }
        return head;
    }
};