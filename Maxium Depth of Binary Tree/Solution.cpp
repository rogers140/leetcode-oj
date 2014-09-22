#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root == NULL) {
        	return 0;
        }
        else {
        	return 1 + max(maxDepth(root->left), maxDepth(root->right));
        }
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
	cout<<s->maxDepth(root)<<endl;
	return 0;
}