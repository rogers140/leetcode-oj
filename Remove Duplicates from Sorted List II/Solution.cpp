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
    		return NULL;
    	}
        ListNode *dummyhead = new ListNode(0);
        dummyhead->next = head;
        int previous = head->val;
        ListNode *front = dummyhead;
        ListNode *end = head;
        bool isDuplicates = false;
        while(end->next != NULL) {
        	if((end->next)->val == previous) {
        		isDuplicates = true;
        		end->next = (end->next)->next;//just delete the duplicate one, left one element
        	}
        	else {
        		//when previous change
        		previous = end->next->val;
        		if(isDuplicates) {//delete the left one
        			front->next = (front->next)->next;
        			isDuplicates = false;
        			end = front->next;
        		}
        		else {
        			end = end->next;
        			front = front->next;
        		}
        	}
        }
        if(isDuplicates) {//in case it reaches the end without delete
        	front->next = (front->next)->next;
        }
        return dummyhead->next;
    }
};
int main(int argc, char const *argv[])
{
	ListNode *head = new ListNode(1);
	ListNode *node2 = new ListNode(1);
	ListNode *node3 = new ListNode(2);
	ListNode *node4 = new ListNode(2);
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