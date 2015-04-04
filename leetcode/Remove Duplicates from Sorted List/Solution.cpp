#include <stdio.h>
#include <iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL) {
        	return head;
        }
        ListNode *result = head;
        while(head->next != NULL) {
        	if((head->next)->val == head->val) {
        		ListNode *temp = (head->next)->next;
        		head->next = temp;
        	}
        	else {
        		head = head->next;
        	}
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
	ListNode *head = new ListNode(1);
	ListNode *node2 = new ListNode(1);
	ListNode *node3 = new ListNode(2);
	ListNode *node4 = new ListNode(3);
	ListNode *node5 = new ListNode(3);
	head->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	Solution *s = new Solution();
	ListNode *result = s->deleteDuplicates(head);
	while(result != NULL) {
		cout<<result->val<<",";
		result = result->next;
	}
	cout<<endl;
	return 0;
}