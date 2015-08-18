#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if(head == NULL) return NULL;
		ListNode* ptr = head->next;  // one step one time
		ListNode* double_ptr;  // two steps one time
		if(ptr != NULL) double_ptr = ptr->next;
		else return NULL;
		while (ptr != NULL && double_ptr != NULL) {
			if (ptr == double_ptr) {
				// found
				// Assume loop entry point x far from head
				// When ptr and double_ptr meet, ptr walks (x+z),
				// double_ptr walks (x+z)+y+z, where z is the distance for ptr
				// surpass entry point, y is more steps it needs to go back to entry
				// so x + z + y + z = 2(x+z), which means, x = y.
				// That is to say, lets head and ptr walk now, when they meet,
				// the meet point is the entry point.
				double_ptr = head;
				while (double_ptr != ptr) {
					double_ptr = double_ptr->next;
					ptr = ptr->next;
				}
				return double_ptr;
			}
			if (double_ptr->next == NULL) break;
			ptr = ptr->next;
			double_ptr = (double_ptr->next)->next;
		}
		return NULL;
	}
};

int main(int argc, char const* argv[]) {
	Solution *s = new Solution();
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);

	n1->next = n2;
	n2->next = n3;
	n3->next = n2;
	cout<<s->detectCycle(n1)->val<<endl;;
}