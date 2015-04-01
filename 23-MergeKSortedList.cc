/**
 * Merge k sorted linked lists and return it as one sorted list. 
 * Analyze and describe its complexity.
 */

 /**
 * Definition for singly-linked list.
 */

 #include <iostream>
 #include <vector>
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Use iteration method to solve this problem
        if (lists.size() == 0) {
        	return NULL;
        }
        if (lists.size() == 1) {
        	return lists[0];
        }
        vector<ListNode *> vListNode = lists;
        while(vListNode.size() > 1) {
        	cout << vListNode.size() << endl;
        	vector<ListNode *> tempVLN;
        	int start = 0;
        	int end = vListNode.size() - 1;
        	while(start < end) {
        		ListNode * lnStart = vListNode[start];
        		ListNode * lnEnd = vListNode[end];
        		ListNode * merged = mergeTwoLists(lnStart, lnEnd);
        		start++;
        		end--;
        		tempVLN.push_back(merged);
        	}
        	if (start == end) tempVLN.push_back(vListNode[start]);
        	// for(int i = 0;i < tempVLN.size();i++) {
        	// 	printf_List(tempVLN[i]);
        	// }
        	vListNode = tempVLN;
        }
        return vListNode[0];
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode * dummy = new ListNode(0);
		ListNode * current = dummy;
		while(l1 != NULL && l2 != NULL) {
			if(l1->val < l2->val) {
				current->next = new ListNode(l1->val);
				current = current->next;
				l1 = l1->next;
			}else {
				current->next = new ListNode(l2->val);
				current = current->next;
				l2 = l2->next;
			}
		}

		if(l1 != NULL) {
			while(l1 != NULL) {
				current->next = new ListNode(l1->val);
				current = current->next;
				l1 = l1->next;
			}
		}else {
			while(l2 != NULL) {
				current->next = new ListNode(l2->val);
				current = current->next;
				l2 = l2->next;
			}
		}
		return dummy->next;
	}
};

int main(int argc, char const *argv[])
{
	Solution * sol = new Solution();
	vector<ListNode *> aVec;
	aVec.push_back(NULL);
	ListNode a(-1);
	ListNode b(5);
	ListNode c(11);
	a.next = &b;b.next = &c;
	aVec.push_back(&a);
	aVec.push_back(NULL);
	ListNode d(6);
	ListNode e(10);
	d.next = &e;
	aVec.push_back(&d);
	ListNode * head = sol->mergeKLists(aVec);
	printf_List(head);
	return 0;
}

