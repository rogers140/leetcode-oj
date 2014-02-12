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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
        	return NULL;
        }
        if (lists.size() == 1) {
        	return lists[0];
        }
        if (lists.size() == 2) {
        	return mergeTwo(lists[0], lists[1]);
        }
        int size = lists.size();
        ListNode *left = merge(lists, 0, size / 2);
        ListNode *right = merge(lists, size / 2 + 1, size - 1);
        return mergeTwo(left, right);

    }
    ListNode *merge(vector<ListNode *> &lists, int l, int r) {
    	if (l == r) {
    		return lists[l];
    	}
    	if (r - l == 1) {
    		return mergeTwo(lists[l], lists[r]);
    	}
    	ListNode *left = merge(lists, l, l + (r - l) / 2);
    	ListNode *right = merge(lists, l + (r - l) / 2 + 1, r);
    	return mergeTwo(left, right);
    }
    ListNode *mergeTwo(ListNode * &left, ListNode * &right) {
    	ListNode *dummyhead = new ListNode(0);
    	ListNode *p = dummyhead;
    	ListNode *left_index = left;
    	ListNode *right_index = right;
    	if (left == NULL) return right;
    	if (right == NULL) return left;
    	while (left_index != NULL && right_index != NULL) {
    		if (left_index->val > right_index->val) {
    			p->next = new ListNode(right_index->val);
    			p = p->next;
    			right_index = right_index->next;

    		}
    		else {
    			p->next = new ListNode(left_index->val);
    			p = p->next;
    			left_index = left_index->next;
    		}
    	}
    	if (left_index == NULL) {
    		if (right_index != NULL) {
    			p->next = right_index;
    		}
    	}
    	else {
    		if (left_index != NULL) {
    			p->next = left_index;
    		}
    	}
    	return dummyhead->next;
    }
};

int main(int argc, char const *argv[]) {
	ListNode *a1 = new ListNode(2);
	ListNode *a2 = new ListNode(4);
	ListNode *a3 = new ListNode(5);
	ListNode *a4 = new ListNode(7);
	ListNode *a5 = new ListNode(32);
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;

	ListNode *b1 = new ListNode(8);
	ListNode *b2 = new ListNode(10);
	ListNode *b3 = new ListNode(14);
	ListNode *b4 = new ListNode(17);
	ListNode *b5 = new ListNode(27);
	ListNode *b6 = new ListNode(39);
	ListNode *b7 = new ListNode(40);
	b1->next = b2;
	b2->next = b3;
	b3->next = b4;
	b4->next = b5;
	b5->next = b6;
	b6->next = b7;

	ListNode *c1 = new ListNode(6);
	ListNode *c2 = new ListNode(9);
	ListNode *c3 = new ListNode(14);
	c1->next = c2;
	c2->next = c3;

	vector<ListNode *> lists;
	lists.push_back(a1);
	lists.push_back(b1);
	lists.push_back(c1);
	// ListNode *n1 = NULL;
	// ListNode *n2 = NULL;
	// lists.push_back(n1);
	// lists.push_back(n2);

	Solution *s = new Solution();
	ListNode *result = s->mergeKLists(lists);

	while (result != NULL) {
		cout<<result->val<<",";
		result = result->next;
	}
	cout<<endl;
	return 0;
}