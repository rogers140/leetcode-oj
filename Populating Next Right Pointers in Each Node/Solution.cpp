#include <stdio.h>
#include <iostream>
using namespace std;
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL){}
};
//assume the tree is perfect binary tree
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if(root == NULL){
    		return;
    	}
        if(root->left != NULL && root->right != NULL){
        	root->left->next = root->right;
        	if(root->next != NULL){
        		root->right->next = root->next->left;
        	}
        	connect(root->left);
        	connect(root->right);
        }
    }
};
int main(int argc, char const *argv[])
{
	TreeLinkNode *node1 = new TreeLinkNode(1);
	TreeLinkNode *node2 = new TreeLinkNode(2);
	TreeLinkNode *node3 = new TreeLinkNode(3);
	TreeLinkNode *node4 = new TreeLinkNode(4);
	TreeLinkNode *node5 = new TreeLinkNode(5);
	TreeLinkNode *node6 = new TreeLinkNode(6);
	TreeLinkNode *node7 = new TreeLinkNode(7);
	node1->left = node2;
	node1->right = node3;

	node2->left = node4;
	node2->right = node5;

	node3->left = node6;
	node3->right = node7;
	Solution *s = new Solution();
	s->connect(node1);
	cout<<node6->next->val<<endl;
	return 0;
}