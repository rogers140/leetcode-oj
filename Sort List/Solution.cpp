#include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode* sortList(ListNode* head) {
  	return mergeSort(head);
  }
  ListNode* mergeSort(ListNode* head) {
  	if(head == NULL) {
  		return head;
  	}
  	if (head->next == NULL) {  // size == 1
  		return head;
  	}
  	if (head->next->next == NULL) {  //size == 2
  		ListNode* second = head->next;
  		head->next = NULL;
  		return merge(head, second);
  	}
  	// Finds the mid and seperates into two lists.
  	ListNode* secondHalf = head;
  	ListNode* faster = head;
  	while (secondHalf != NULL && faster != NULL && faster->next != NULL) {
  		secondHalf = secondHalf->next;
  		faster = (faster->next)->next;
  	}

  	ListNode* second = mergeSort(secondHalf->next);
  	secondHalf->next = NULL;
  	ListNode* first = mergeSort(head);
  	return merge(first, second);
  	

  }
  ListNode* merge(ListNode* first, ListNode* second) {
  	// Merges two sorted list.
  	ListNode* dummyhead = new ListNode(-1);
  	ListNode* current = dummyhead;
  	ListNode* next;
  	while (first != NULL && second != NULL) {
  		if (first->val <= second->val) {
  			current->next = first;
  			next = first->next;
  			first->next = NULL;
  			first = next;
  		} else {
  			current->next = second;
  			next  = second->next;
  			second->next = NULL;
  			second = next;
  		}
  		current = current->next;
  	}
  	if (first != NULL && second == NULL) {
  		current->next = first;
  	} else if (first == NULL && second != NULL) {
  		current->next = second;
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
	// n1->next = n6;
	// n6->next = n7;

	Solution *s = new Solution();
	ListNode* result = s->sortList(n2);
	while(result != NULL) {
		cout<<result->val<<", ";
		result = result->next;
	}
	cout<<endl;
	return 0;
}