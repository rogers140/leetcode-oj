#include <iostream>
#include <unordered_map>
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
	int sumNumbers(TreeNode* root) {
		vector<TreeNode*> leaf_list;
		unordered_map<TreeNode*, TreeNode*> father_map;
		vector<TreeNode*> stack;
		TreeNode* current = root;
		// DFS, left / root / right
		while (current != NULL) {
			if (current->left == NULL && current->right == NULL) {
				leaf_list.push_back(current);
				while (!stack.empty() && (stack.back()->right) == NULL) {
					stack.pop_back();
				}
				if (stack.empty()) break;	
				current = stack.back()->right;
				father_map[current] = stack.back();
				stack.pop_back();
			} else if (current->left == NULL) {
				father_map[current->right] = current;
				current = current->right;
			} else if (current->right == NULL) {
				father_map[current->left] = current;
				current = current->left;
			} else {
				father_map[current->left] = current;
				stack.push_back(current);
				current = current->left;
			}
		}
		int sum = 0;
		for (TreeNode* leaf : leaf_list) {
			int level = 1;
			while (father_map.find(leaf) != father_map.end()) {
				sum += leaf->val * level;
				leaf = father_map[leaf];
				level *= 10;
			}
			sum += leaf->val * level; // root
		}
		return sum;
	}
};
int main(int argc, char const* argv[]) {
	Solution *s = new Solution();
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);

	n1->left = n2;
	n1->right = n5;
	n2->left = n3;
	n2->right = n6;
	n3->right = n4;

	cout<<s->sumNumbers(n1)<<endl;
	return 0;
}