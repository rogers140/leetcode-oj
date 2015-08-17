#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if(head == NULL) return false;
		ListNode* ptr = head->next;  // one step one time
		ListNode* double_ptr;  // two steps one time
		if(ptr != NULL) double_ptr = ptr->next;
		else return false;
		bool foundCycle = false;
		while (ptr != NULL && double_ptr != NULL) {
			if (ptr == double_ptr) {
				foundCycle = true;
				break;
			}
			if (double_ptr->next == NULL) break;
			ptr = ptr->next;
			double_ptr = (double_ptr->next)->next;
		}
		return foundCycle;
	}
};

int main(int argc, char const* argv[]) {
	Solution *s = new Solution();
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);

	n1->next = n1;
	n2->next = n1;
	cout<<s->hasCycle(n1)<<endl;;
}