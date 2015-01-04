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
    void flatten(TreeNode *root) {
        if(root == NULL || (root->left == NULL && root->right == NULL)) {
        	return;
        }
        else if(root->left == NULL) {
        	flatten(root->right);
        	return;
        }
        else if(root->right == NULL) {
        	root->right = root->left;
        	root->left = NULL;
        	flatten(root->right);
        }
        else {
        	flatten(root->left);
        	flatten(root->right);
        	TreeNode *left = root->left;
        	while(left->right != NULL) {
        		left = left->right;
        	}
        	//cout<<"left link: "<<left->val<<endl;
        	left->right = root->right;
        	//cout<<"right link: "<<root->right->val<<endl;
        	root->right = root->left;
        	root->left = NULL;
        }
    }
};
int main(int argc, char const *argv[])
{
	TreeNode *root = new TreeNode(1);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node3 = new TreeNode(3);
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node5 = new TreeNode(5);
	TreeNode *node6 = new TreeNode(6);

	root->left = node2;
	root->right = node5;
	node2->left = node3;
	node2->right = node4;
	node5->right = node6;

	Solution *s = new Solution();
	s->flatten(root);
	while(root!= NULL) {
		cout<<root->val<<endl;
		root = root->right;
	}
	return 0;
}