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
        	currentQ = currentQ->right;
        }
        if(currentQ != NULL || stackQ.size() != 0) {
        	return false;
        }
        return true;
    }
    bool isSameTree_recursionVersion(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) return true;               //Base Case
        return p && q && (p->val == q->val) && isSameTree_recursionVersion(p->left, q->left) && isSameTree_recursionVersion(p->right, q->right);
    }
};
int main(int argc, char const *argv[])
{
    TreeNode *node21 = new TreeNode(2);
    TreeNode *node22 = new TreeNode(2);
    TreeNode *node31 = new TreeNode(3);
    TreeNode *node32 = new TreeNode(3);
    TreeNode *node41 = new TreeNode(4);
    node21->right = node31;
    node22->right = node32;
    node22->left = node41;
    Solution *s = new Solution();
    cout<<s->isSameTree(node21, node22)<<endl;
	return 0;
}