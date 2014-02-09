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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
    	if (n == 0) {
    		return head;
    	}
    	ListNode *front;
    	ListNode *back;
    	ListNode *virtual_head = new ListNode(0);
    	front = virtual_head;
    	back = virtual_head;
    	virtual_head->next = head;
    	for (int i = 0; i < n; ++i) {
    		front = front->next;
    	}
    	while (front->next != NULL) {
    		front = front->next;
    		back = back->next;
    	}
    	back->next = (back->next)->next;
        return virtual_head->next;
    }
};

int main(int argc, char const *argv[]) {
	Solution *s = new Solution();
	ListNode *head = new ListNode(1);
	ListNode *node1 = new ListNode(2);
	ListNode *node2 = new ListNode(3);
	ListNode *node3 = new ListNode(4);
	ListNode *node4 = new ListNode(5);
	head->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	ListNode *result = s->removeNthFromEnd(head, 1);

	while (result != NULL) {
		cout<<result->val<<",";
		result = result->next;
	}
	cout<<endl;
	return 0;
}
