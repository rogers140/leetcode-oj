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
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
    	if(root == NULL) {
    		return true;
    	}
        if(root->left != NULL) {
        	if(root->right == NULL) {
        		return false;
        	}
        	else {
        		return isSymmetricTrees(root->left, root->right);
        	}
        }
        else {
        	if(root->right == NULL) {
        		return true;
        	}
        	else {
        		return false;
        	}
        }
    }
    bool isSymmetricTrees(TreeNode *p, TreeNode *q) {
        vector<TreeNode *> stackP;
        vector<TreeNode *> stackQ;
        TreeNode *currentP = p;
        TreeNode *currentQ = q;
        while(currentP != NULL || stackP.size() != 0) {
        	while(currentP != NULL) {
        		stackP.push_back(currentP);
        		if(currentQ == NULL) {
        			return false;
        		}
        		stackQ.push_back(currentQ);
        		currentP = currentP->left;
        		currentQ = currentQ->right;
        	}
        	if(currentQ != NULL) {
        		return false;
        	}
        	currentP = stackP.back();
        	if(stackQ.size() == 0) {
        		return false;
        	}
        	currentQ = stackQ.back();
        	if(currentP->val != currentQ->val) {
        		return false;
        	}
        	stackP.pop_back();
        	stackQ.pop_back();
        	currentP = currentP->right;
        	currentQ = currentQ->left;
        }
        if(currentQ != NULL || stackQ.size() != 0) {
        	return false;
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node21 = new TreeNode(2);
	TreeNode *node22 = new TreeNode(2);
	TreeNode *node31 = new TreeNode(3);
	TreeNode *node32 = new TreeNode(3);
	TreeNode *node41 = new TreeNode(4);
	node21->right = node31;
	node22->left = node32;
	node22->right = node41;
	node1->left = node21;
	node1->right = node22;

	cout<<s->isSymmetric(node1)<<endl;
	return 0;
}