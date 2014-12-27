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
//we reused the code of level order traversal, and then reverse the final
//result.
class Solution {
public:
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > result = levelOrder(root);
		reverse(result.begin(), result.end());
		return result;
	}
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if(root == NULL) {
        	return result;
        }
        vector<int> currentRow;
        currentRow.push_back(root->val);
        result.push_back(currentRow);
        vector<vector<int> > leftTreeTraversal = levelOrder(root->left);
        vector<vector<int> > rightTreeTraversal = levelOrder(root->right);
        int depth = 0;
        while(depth < leftTreeTraversal.size() || depth < rightTreeTraversal.size()) {
        	if(depth >= leftTreeTraversal.size()) {
        		if(depth >= rightTreeTraversal.size()) {
        			break;
        		}
        		else {
        			result.push_back(rightTreeTraversal[depth]);
        			++depth;
        		}
        	}
        	else {
        		if(depth >= rightTreeTraversal.size()) {
        			result.push_back(leftTreeTraversal[depth]);
        		}
        		else {
        			vector<int> row(leftTreeTraversal[depth]);
        			row.insert(row.end(), rightTreeTraversal[depth].begin(), rightTreeTraversal[depth].end());
        			result.push_back(row);
        		}
        		++depth;
        	}
        }
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
	vector<vector<int> > result = s->levelOrderBottom(root);
	for(int i = 0; i < result.size(); ++i) {
		for(int j = 0; j < result[i].size(); ++j) {
			cout<<result[i][j]<<",";
		}
		cout<<endl;
	}
	return 0;
}