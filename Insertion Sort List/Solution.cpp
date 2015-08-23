#include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* dummyhead = new ListNode(-1);
		dummyhead->next = head;
		// Seperates waiting list from main.
		ListNode* wait_head = head->next;
		head->next = NULL;

		ListNode* curr = wait_head;
		while (curr != NULL) {
			ListNode* ptr = dummyhead->next;
			ListNode* parent = dummyhead;
			while (ptr != NULL && ptr->val < curr->val) {
				ptr = ptr->next;
				parent = parent->next;
			}
			parent->next = curr;
			ListNode* next = curr->next;
			curr->next = ptr;
			curr = next;
		}

		return dummyhead->next;
	}
};
int main(int argc, char const *argv[])
{
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
	ListNode* n6 = new ListNode(6);
	ListNode* n7 = new ListNode(7);

	n2->next = n4;
	n4->next = n3;
	n3->next = n5;
	n5->next = n1;
	n1->next = n6;
	n6->next = n7;

	Solution *s = new Solution();
	ListNode* result = s->insertionSortList(n2);
	while(result != NULL) {
		cout<<result->val<<", ";
		result = result->next;
	}
	cout<<endl;
	return 0;
}