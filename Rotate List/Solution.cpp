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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL) {
            return head;
        }
        ListNode *fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode *currentNode = fakeHead;
        ListNode *breakPoint = NULL;
        ListNode *countNode = head;
        int length = 0;
        while(countNode != NULL) {
            ++length;
            countNode = countNode->next;
        }
        k = k % length;
        k = length - k - 1;
        while(currentNode->next != NULL) {
        	currentNode = currentNode->next;
        	if(k == 0) {
        		breakPoint = currentNode;
        	}
        	--k;
        }
        if(breakPoint != NULL) {
        	currentNode->next = fakeHead->next;
        	fakeHead->next = breakPoint->next;
        	breakPoint->next = NULL;

        }
        return fakeHead->next;
    }
};
int main(int argc, char const *argv[])
{
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);
	ListNode *node5 = new ListNode(5);
	node1->next = node2;
	// node2->next = node3;
	// node3->next = node4;
	// node4->next = node5;

	Solution *s = new Solution();
	ListNode *result = s->rotateRight(node1, 0);
	while(result != NULL) {
		cout<<result->val<<", ";
        result = result->next;
	}
	cout<<endl;
	return 0;
}