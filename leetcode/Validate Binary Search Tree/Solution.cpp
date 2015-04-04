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
    bool isValidBST(TreeNode *root) {
        vector<int> result;
        vector<TreeNode *> stack;
        TreeNode *current = root;
        while(current != NULL || stack.size() != 0) {
        	while(current != NULL) {
        		stack.push_back(current);
        		current = current->left;
        	}
        	current = stack.back();
        	stack.pop_back();
        	if(result.size() != 0 && current->val <= result.back()) {
        		return false;
        	}
        	result.push_back(current->val);
        	current = current->right;
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
	TreeNode *root = new TreeNode(1);
	TreeNode *node1 = new TreeNode(1);
	//TreeNode *node2 = new TreeNode(3);
	root->left = node1;
	//root->right = node2;
	Solution *s = new Solution();
	cout<<s->isValidBST(root)<<endl;
	return 0;
}