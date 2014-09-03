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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
    	if(m == n) {
    		return head;
    	}
        ListNode *mPtr = head;
        ListNode *nPtr = head;
        ListNode *begin = new ListNode(0);
        begin->next = head;
        ListNode *end = NULL;
        int start = m;
        while(m > 1) {
        	begin = begin->next;
        	mPtr = mPtr->next;
        	--m;
        }
        while(n > 1) {
        	nPtr = nPtr->next;
        	--n;
        }
        end = nPtr->next;
        ListNode *current = mPtr;
        ListNode *pre = end;
        while(current != end) {
        	ListNode *next = current->next;
        	if(next == end) {
        		begin->next = current;
        	}
        	current->next = pre;
        	pre = current;
        	current = next;
        }
        begin->next = nPtr;
        if(start == 1) {
        	return begin->next;
        }
        else {
        	return head;
        }
    }
};
int main(int argc, char const *argv[])
{
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);
	ListNode *node5 = new ListNode(5);
	ListNode *node6 = new ListNode(6);
	ListNode *node7 = new ListNode(7);
	ListNode *node8 = new ListNode(8);
	ListNode *node9 = new ListNode(9);
	ListNode *node10 = new ListNode(10);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;
	node7->next = node8;
	node8->next = node9;
	node9->next = node10;

	Solution *s = new Solution();
 	ListNode *result = s->reverseBetween(node1, 1, 2);
 	while(result != NULL) {
 		cout<<result->val<<", "<<endl;
 		result = result->next;
 	}
	return 0;
}