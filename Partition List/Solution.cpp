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
    ListNode *partition(ListNode *head, int x) {
        ListNode *leftHead = new ListNode(0);
        ListNode *leftPtr = leftHead;
        ListNode *rightHead = new ListNode(0);
        ListNode *rightPtr = rightHead;
        if(head == NULL || head->next == NULL) {
        	return head;
        }
        while(head != NULL) {   	
        	int currentVal = head->val;
        	ListNode *temp = head;
        	if(currentVal < x) {    		
        		leftPtr->next = temp;
        		leftPtr = leftPtr->next;
        	}
        	else {
        		rightPtr->next = temp;
        		rightPtr = rightPtr->next;
        	}
        	head = head->next;
        }
        leftPtr->next = rightHead->next;
        rightPtr->next = NULL;//avoid infinit loop
        return leftHead->next;
    }
};
int main(int argc, char const *argv[])
{
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(4);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(2);
	ListNode *node5 = new ListNode(5);
	ListNode *node6 = new ListNode(2);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;

	Solution *s = new Solution();
	ListNode *result = s->partition(node1, 3);
	while(result != NULL) {
		cout<<result->val<<", ";
		result = result->next;
	}
	cout<<endl;
	return 0;
}