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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL) {
            return head;
        }
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode *pre, *current, *next;
        int reverseTimes = 0;
        int length = 0;
        ListNode *index = head;
        while(index != NULL) {
        	index = index->next;
        	++length;
        }
        reverseTimes = length/k;  // Decides how many groups
        pre = NULL;
        current = head;
        next = NULL;
        ListNode *end;
        end = NULL;
        if(reverseTimes > 0) {
        	int group_length = k;
            end = current;
        	while (group_length != 0) {
        		next = current->next;
        		current->next = pre;
        		pre = current;
        		current = next;
                --group_length;
        	}
            dummy_head->next = pre;
            end->next = reverseKGroup(current, k);      	
        }
        else {
            return head;
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

	ListNode *result = s->reverseKGroup(a1, 3);
	while (result != NULL) {
		cout<<result->val<<",";
		result = result->next;
	}
	cout<<endl;

	return 0;
}