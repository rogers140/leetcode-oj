#include <stdio.h>
#include <iostream>
#include <vector>  
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
    	vector<int> num;
        while(head != NULL) {
        	num.push_back(head->val);
        	head = head->next;
        }
        return sortedArrayToBST(num);

    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int size = num.size();
        if(size == 0) {
        	return NULL;
        }
        if(size == 1) {
        	TreeNode *root = new TreeNode(num[0]);
        	return root;
        }
        if(size == 2) {
        	TreeNode *root = new TreeNode(num[1]);
        	TreeNode *left = new TreeNode(num[0]);
        	root->left = left;
        	return root;
        }
        int middle = size / 2;
        TreeNode *root = new TreeNode(num[middle]);
        vector<int> left(num.begin(), num.begin() + middle);
        vector<int> right(num.begin() + middle + 1, num.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
};