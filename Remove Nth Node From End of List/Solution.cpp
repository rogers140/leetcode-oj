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
    ListNode *removeNthFromEnd(ListNode *head, int n) {//could use two pointer with distance of n
    	vector<ListNode *> tmp;
    	ListNode *ptr = head;
    	for (int i = 0; i < n; ++i) {
    		tmp.push_back(ptr);
    		ptr = ptr->next;
    	}
    	if (ptr == NULL) {
    		head = head->next;
    		return head;
    	}
    	while (ptr->next != NULL) {
    		for (int i = 0; i < n - 1; ++i) {
    			tmp[i] = tmp[i+1];
    		}
    		tmp[n - 1] = ptr;
    		ptr = ptr->next;
    	}
    	if (n == 1) {
    		tmp[0]->next = NULL;
    	}
    	if (n == 2) {
    		tmp[0]->next = ptr;
    	}
    	if (n > 2) {
    		tmp[0]->next = tmp[2];
    	}
    	
    	return head;
        
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
	ListNode *result = s->removeNthFromEnd(head, 5);

	while (result != NULL) {
		cout<<result->val<<",";
		result = result->next;
	}
	cout<<endl;
	return 0;
}
