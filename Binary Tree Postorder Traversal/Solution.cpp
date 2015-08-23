#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		// left right root
		vector<int> result;
		if (root == NULL) return result;
		vector<TreeNode*> stack;
		TreeNode* current = root;
		do {
			while (current != NULL) {
				if (current->right != NULL) {
					stack.push_back(current->right);
				}
				stack.push_back(current);
				current = current->left;
			}
			current = stack.back();
			stack.pop_back();
			if (!stack.empty() && current->right == stack.back()) {
				stack.pop_back();
				stack.push_back(current);
				current = current->right;
			} else {
				result.push_back(current->val);
				current = NULL;
			}

		} while (!stack.empty());

		return result;
	}
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);
	TreeNode* n7 = new TreeNode(7);
	n1->left = n2;
	n1->right = n3;
	n2->right = n4;
	n3->left = n5;
	n3->right = n6;
	n4->left = n7;

	vector<int> result = s->postorderTraversal(n1);
	for (int i : result) {
		cout<<i<<", ";
	}
	cout<<endl;
	return 0;
}