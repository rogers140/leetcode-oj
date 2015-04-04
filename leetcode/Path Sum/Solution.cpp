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
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL) {
        	return false;
        }
        else {
        	return hasPathSum_aux(root, sum);
        }
    }
    bool hasPathSum_aux(TreeNode *root, int sum) {
    	if(root == NULL) {
        	return (sum == 0);
        }
        else {
        	if(root->left == NULL && right == NULL) {
        		return (sum == root->val);
        	}
        	else if(root->left == NULL) {
        		return hasPathSum_aux(root->right, sum - root->val);
        	}
        	else if(root->right == NULL) {
        		return hasPathSum_aux(root->left, sum - root->val);
        	}
        	else {
        		return hasPathSum_aux(root->left, sum - root->val) 
        			|| hasPathSum_aux(root->right, sum - root->val);
        	}
        	
        }
    }
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	TreeNode *root = new TreeNode(1);
	TreeNode *node1 = new TreeNode(2);
	root->left = node1;
	cout<<s->hasPathSum(root, 1)<<endl;
	return 0;
}