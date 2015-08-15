#include <iostream>
#include <algorithm>
#include <limits>
#include <utility>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
	typedef pair<int, int> MaxSum;
public:
	MaxSum getMax(TreeNode* root) {
		if (root == NULL) return (make_pair(0, numeric_limits<int>::min()));
		MaxSum left_sum = getMax(root->left);
		MaxSum right_sum = getMax(root->right);
		int root_only = root->val;
		int left_root_right = left_sum.first + root_only + right_sum.first;
		int root_as_end_or_start = max(root_only, max(left_sum.first, right_sum.first) + root_only);
		int max_value = max(left_root_right, max(root_as_end_or_start, max(left_sum.second, right_sum.second)));
		return (make_pair(root_as_end_or_start, max_value));
	}

	int maxPathSum(TreeNode* root) {
		return getMax(root).second;
	}
};

int main(int argc, char const *argv[])
{
	
	return 0;
}
