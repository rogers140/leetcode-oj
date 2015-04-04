#include <stdio.h>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
    	if (head == NULL || head->next == NULL) {
    		return head;
    	}
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode *i = dummy_head;
        ListNode *j = i->next;
        ListNode *k = j->next;
        while (1) {
        	i->next = k;
        	j->next = k->next;
        	k->next = j;
        	i = j;
        	if (i->next == NULL) {
        		break;
        	}
        	j = i->next;
        	if (j->next == NULL){
        		break;
        	}
        	k = j->next;
        }
        return dummy_head->next;
    }
};

int main(int argc, char const *argv[]) {
	Solution *s = new Solution();
	ListNode *a1 = new ListNode(1);
	ListNode *a2 = new ListNode(2);
	ListNode *a3 = new ListNode(3);
	ListNode *a4 = new ListNode(4);
	ListNode *a5 = new ListNode(5);
	ListNode *a6 = new ListNode(6);

	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;
	a5->next = a6;

	ListNode *result = s->swapPairs(a1);
	while (result != NULL) {
		cout<<result->val<<",";
		result = result->next;
	}
	cout<<endl;

	return 0;
}