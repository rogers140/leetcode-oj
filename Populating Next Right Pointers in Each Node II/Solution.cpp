#include <stdio.h>
#include <iostream>
using namespace std;
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL){}
};
//assume the tree may not be a perfect binary tree
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if(root == NULL){
    		return;
    	}
        if(root->left != NULL && root->right != NULL){
        	root->left->next = root->right;
        	TreeLinkNode * next = root->next;
        	while(next != NULL) { //keep searching until find null
        		if(next->left != NULL){
        			root->right->next = next->left;
        			break;
        		}
        		else if(next->right != NULL) {
        			root->right->next = next->right;
        			break;
        		}
        		else {
        			next = next->next;
        		}
        	}
        	connect(root->right); //first right, then left
        	connect(root->left);
        }
        else if(root->left == NULL && root->right != NULL){ //left child is null
        	TreeLinkNode * next = root->next; 
        	while(next != NULL) { //keep searching until find null
        		if(next->left != NULL){
        			root->right->next = next->left;
        			break;
        		}
        		else if(next->right != NULL) {
        			root->right->next = next->right;
        			break;
        		}
        		else {
        			next = next->next;
        		}
        	}
        	connect(root->right);
        }
        else if(root->left != NULL && root->right == NULL){ //right child is null
        	TreeLinkNode * next = root->next; 
        	while(next != NULL) { //keep searching until find null
        		if(next->left != NULL){
        			root->left->next = next->left;
        			break;
        		}
        		else if(next->right != NULL) {
        			root->left->next = next->right;
        			break;
        		}
        		else {
        			next = next->next;
        		}
        	}
        	connect(root->left);
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

	TreeLinkNode *node8 = new TreeLinkNode(8);
	TreeLinkNode *node9 = new TreeLinkNode(9);
	TreeLinkNode *node10 = new TreeLinkNode(10);
	TreeLinkNode *node11 = new TreeLinkNode(11);
	TreeLinkNode *node12 = new TreeLinkNode(12);
	TreeLinkNode *node13 = new TreeLinkNode(13);
	TreeLinkNode *node14 = new TreeLinkNode(14);
	TreeLinkNode *node15 = new TreeLinkNode(15);

	node1->left = node2;
	node1->right = node3;

	node2->left = node4;
	node2->right = node5;

	node3->left = node6;
	node3->right = node7;

	node4->left = node8;
	node4->right = node9;

	node5->left = node10;
	node5->right = node11;

	//node6->left = node12;
	//node6->right = node13;

	node7->left = node14;
	node7->right = node15;
	Solution *s = new Solution();

	s->connect(node1);
	cout<<node11->next->val<<endl;
	return 0;
}