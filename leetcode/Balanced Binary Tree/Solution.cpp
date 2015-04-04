#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>  
#include <unordered_map>  
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	unordered_map<TreeNode*, int> heightHash; //using DP
    bool isBalanced(TreeNode *root) {
        if(root == NULL) {
        	return true;
        }
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if(leftHeight - rightHeight <=1 && leftHeight - rightHeight >= -1) {
        	return (isBalanced(root->left) && (isBalanced(root->right)));
        }
        else {
        	return false;
        }
    }
    int getHeight(TreeNode *root) {
    	if(heightHash.find(root) != heightHash.end()) {
    		return heightHash[root];
    	}
    	if(root == NULL) {
    		heightHash[root] = 0;
    		return 0;
    	}
    	TreeNode *left = root->left;
    	TreeNode *right = root->right;
    	if(left == NULL && right == NULL) {
    		return 1;
    	}
    	int leftHeight = getHeight(left);
    	int rightHeight = getHeight(right);

    	int result = (leftHeight > rightHeight) ? 
    				(leftHeight + 1) : (rightHeight + 1);
    	heightHash[root] = result;
    	return result;
    }
};
int main(int argc, char const *argv[])
{
	TreeNode *root = new TreeNode(3);
	TreeNode *node1 = new TreeNode(9);
	TreeNode *node2 = new TreeNode(20);
	TreeNode *node3 = new TreeNode(15);
	TreeNode *node4 = new TreeNode(17);

	node2->left = node3;
	node2->right = node4;
	root->left = node1;
	root->right = node2;

	Solution *s = new Solution();
	cout<<s->isBalanced(root)<<endl;
	return 0;
}