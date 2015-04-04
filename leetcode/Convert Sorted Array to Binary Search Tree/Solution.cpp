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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int size = num.size();
        if(size == 0) {
        	return NULL;
        }
        if(size == 1) {
        	TreeNode *root = new TreeNode(num[0]);
        	return root;
        }
        if(size == 2) {
        	TreeNode *root = new TreeNode(num[1]);
        	TreeNode *left = new TreeNode(num[0]);
        	root->left = left;
        	return root;
        }
        int middle = size / 2;
        TreeNode *root = new TreeNode(num[middle]);
        vector<int> left(num.begin(), num.begin() + middle);
        vector<int> right(num.begin() + middle + 1, num.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
};
int main(int argc, char const *argv[])
{
	int sorted[] = {1,3,5,7,8,11,23};
	vector<int> num(sorted, sorted + 7);
	Solution *s = new Solution();
	TreeNode *root = s->sortedArrayToBST(num);
	return 0;
}