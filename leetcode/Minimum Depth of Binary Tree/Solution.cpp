#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(root == NULL) {
        	return 0;
        }
        else {
        	if(root->left == NULL && root->right == NULL) {//leaf node
        		return 1;
        	}
        	else if(root->left == NULL) {
        		return minDepth(root->right) + 1;
        	}
        	else if(root->right == NULL) {
        		return minDepth(root->left) + 1;
        	}
        	else {
        		int leftMin = minDepth(root->left);
        		int rightMin = minDepth(root->right);
        		return (leftMin < rightMin) ? (leftMin + 1) : (rightMin + 1);
        	}
        	
        }
    }
};