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
	void reorderList(ListNode* head) {
		// Gets size of this list.
		ListNode *ptr = head;
		int size = 0;
		while (ptr != NULL) {
			++size;
			ptr = ptr->next;
		}
		if (size <= 2) return;  // No need to reorder.
		const int mid = size / 2;
		// cout<<"Mid: "<<mid<<endl;
		int count = 0;
		ListNode* first = head;
		ListNode* second = head->next;
		ListNode* third = second->next;
		while (count != mid) {
			++count;
			first = first->next;
			second = second->next;
			third = third->next;
		}
		// cout<<"First: "<<first->val<<endl;
		// Now first points the mid.
		// Reveses the second half
		count = 0;  // count how many link we have reversed
		first->next = NULL;
		while (third != NULL) {
			// cout<<"second: "<<second->val<<" first: "<<first->val<<endl;
			second->next = first;
			first = second;
			second = third;
			third = third->next;
			++count;
		}
		second->next = first;
		// cout<<"second: "<<second->val<<" first: "<<first->val<<endl;
		++count;
		// cout<<"Changed: "<<count<<endl;
		ListNode* tail = second;
		// cout<<"Tail: "<<tail->val<<endl;
		ptr = head;
		// Changes links.
		while (count > 0) {
			ListNode* head_next = ptr->next;
			ListNode* tail_next = tail->next;
			ptr->next = tail;
			tail->next = head_next;
			ptr = head_next;
			tail = tail_next;
			// cout<<"head: "<<ptr->val<<", tail: "<<tail->val<<endl;
			--count;
		}
	}
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	ListNode* n0 = new ListNode(0);
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
	ListNode* n6 = new ListNode(6);
	ListNode* n7 = new ListNode(7);
	ListNode* n8 = new ListNode(8);
	ListNode* n9 = new ListNode(9);
	ListNode* n10 = new ListNode(10);

	n0->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;
	n8->next = n9;
	n9->next = n10;

	s->reorderList(n0);
	ListNode* head = n0;
	while (head != NULL) {
		cout<<head->val<<", ";
		head = head->next;
	}
	cout<<endl;
	return 0;
}