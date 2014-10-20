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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return create(preorder, inorder, 0, 0, preorder.size());
    }
    TreeNode *create(vector<int> &preorder, vector<int> &inorder, int preStart, int inStart, int length) {
    	if(length <= 0) {
    		return NULL;
    	}
    	TreeNode *root = new TreeNode(preorder[preStart]);
    	int rootPos = getPosition(root->val, inorder, inStart);
    	if(rootPos == -1) {
    		return NULL;
    	}
    	int leftLen = rootPos - inStart;
    	int rightLen = length - leftLen - 1;
    	root->left = create(preorder, inorder, preStart + 1, inStart, leftLen);
    	root->right = create(preorder, inorder, preStart + leftLen + 1, rootPos + 1, rightLen);
    	return root;
    }
    int getPosition(int val, vector<int> &inorder, int start) {
    	for(int i = start; i < inorder.size(); ++i) {
    		if(inorder[i] == val) {
    			return i;
    		}
    	}
    	return -1;
    }
};
int main(int argc, char const *argv[])
{
	
	return 0;
}