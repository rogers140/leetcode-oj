#include <iostream>
#include <unordered_set>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		unordered_set<ListNode*> record;
		while (head != NULL) {
			if (record.find(head) == record.end()) {
				record.insert(head);
				head = head->next;
			} else {
				return head;
			}
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