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
    bool isSameTree(TreeNode *p, TreeNode *q) {
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
        		currentQ = currentQ->left;
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
        	currentQ = currentQ->right;
        }
        if(currentQ != NULL || stackQ.size() != 0) {
        	return false;
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
	
	return 0;
}