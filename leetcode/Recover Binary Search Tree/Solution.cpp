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
//morris traversal 
class Solution {
public:
    void recoverTree(TreeNode *root) {
        if(root == NULL) {
        	return;
        }
        //node for traversal
        TreeNode *current = root;
        TreeNode *previous = NULL;

        //node for store the inappropriate node
        TreeNode * pred1, * cur1, * pred2, * cur2;
        pred1 = cur1 = pred2 = cur2 = NULL;
        while(current != NULL) {   	
        	if(current->left == NULL) {
        		previous = current;
        		current = current->right;
        	}
        	else {
        		TreeNode *ptr = current->left;
        		while(ptr->right != NULL && ptr->right != current) {
        			ptr = ptr->right;
        		}
        		if(ptr->right == NULL) {
        			ptr->right = current;
        			current = current->left;
        		}
        		else {
        			ptr->right = NULL;
        			previous = current;
        			current = current->right;
        		}
        	}
        	if(previous != NULL && current != NULL && previous->val > current->val) {
        		if(pred1 == NULL) {
        			pred1 = previous;
        			cur1 = current;
        		}
        		else {
        			pred2 = previous;
        			cur2 = current;
        		}
        	}
        }
        int tmp;
      	if(pred1 != NULL && cur2 != NULL){
      		tmp = pred1->val;
          	pred1->val = cur2->val;
          	cur2->val = tmp;
      	}
      	else{  
          	tmp = pred1->val; 
          	pred1->val = cur1->val; 
          	cur1->val = tmp; 
      	}      
        
    }
};
int main(int argc, char const *argv[])
{
	TreeNode *node0 = new TreeNode(0);
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node3 = new TreeNode(3);
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node5 = new TreeNode(5);
	TreeNode *node6 = new TreeNode(6);

	node1->left = node0;
	node1->right = node6;
	node4->right = node5;
	node2->left = node4;
	node3->right = node2;
	Solution *s = new Solution();
	s->recoverTree(node3);
	return 0;
}