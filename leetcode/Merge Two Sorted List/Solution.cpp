#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummyhead = new ListNode(0);
    	ListNode *p = dummyhead;
    	ListNode *left_index = l1;
    	ListNode *right_index = l2;
    	if (l1 == NULL) return l2;
    	if (l2 == NULL) return l1;
    	while (left_index != NULL && right_index != NULL) {
    		if (left_index->val > right_index->val) {
    			p->next = new ListNode(right_index->val);
    			p = p->next;
    			right_index = right_index->next;

    		}
    		else {
    			p->next = new ListNode(left_index->val);
    			p = p->next;
    			left_index = left_index->next;
    		}
    	}
    	if (left_index == NULL) {
    		if (right_index != NULL) {
    			p->next = right_index;
    		}
    	}
    	else {
    		if (left_index != NULL) {
    			p->next = left_index;
    		}
    	}
    	return dummyhead->next;
    }
};
int main(int argc, char const *argv[])
{
	ListNode *a1 = new ListNode(2);
	ListNode *a2 = new ListNode(4);
	ListNode *a3 = new ListNode(5);
	ListNode *a4 = new ListNode(7);
	ListNode *a5 = new ListNode(32);
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;

	ListNode *b1 = new ListNode(8);
	ListNode *b2 = new ListNode(10);
	ListNode *b3 = new ListNode(14);
	ListNode *b4 = new ListNode(17);
	ListNode *b5 = new ListNode(27);
	ListNode *b6 = new ListNode(39);
	ListNode *b7 = new ListNode(40);
	b1->next = b2;
	b2->next = b3;
	b3->next = b4;
	b4->next = b5;
	b5->next = b6;
	b6->next = b7;

	Solution *s = new Solution();
	ListNode *result = s->mergeTwoLists(a1, b1);
	while (result != NULL) {
		cout<<result->val<<",";
		result = result->next;
	}
	cout<<endl;
	return 0;
}