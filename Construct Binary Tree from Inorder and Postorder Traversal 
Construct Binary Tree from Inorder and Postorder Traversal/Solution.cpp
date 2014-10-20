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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        //postoder should start from end
        return create(postorder, inorder, postorder.size() - 1, 0, inorder.size());
    }
    TreeNode *create(vector<int> &postorder, vector<int> &inorder, int postStart, int inStart, int length) {
        if(length <= 0) {
            return NULL;
        }
    	TreeNode *root = new TreeNode(postorder[postStart]);
        int rootPos = getPosition(root->val, inorder, inStart);
        if(rootPos == -1) {
            return NULL;
        }
        int leftLen = rootPos - inStart;
        int rightLen = length - 1 - leftLen;
        root->right = create(postorder, inorder, postStart - 1, rootPos + 1, rightLen);
        root->left = create(postorder, inorder, postStart -1 - rightLen, inStart, leftLen);
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