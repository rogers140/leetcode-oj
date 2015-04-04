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
    vector<int> inorderTraversal(TreeNode *root) {
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
        	result.push_back(current->val);
        	current = current->right;
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
	TreeNode *root = new TreeNode(1);
	TreeNode *node1 = new TreeNode(2);
	TreeNode *node2 = new TreeNode(3);
	node1->left = node2;
	root->right = node1;

	Solution *s = new Solution();
	vector<int> result = s->inorderTraversal(root);
	for(int i = 0; i < result.size(); ++i) {
		cout<<result[i]<<", ";
	}
	cout<<endl;
	return 0;
}