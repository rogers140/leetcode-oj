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
    vector<TreeNode *> generateTrees(int n) {
    	if(n == 0) {
    		vector<TreeNode *> result;
    		result.push_back(NULL);
    		return result;
    	}
        return generateTrees_aux(1, n);
    }
    vector<TreeNode *> generateTrees_aux(int start, int end) {    	
    	vector<TreeNode *> result;
    	if(start == end) {
    		TreeNode *root = new TreeNode(start);
    		result.push_back(root);
    		return result;
    	}
    	for(int i = start; i <= end; ++i) {//i is root	 		
    		if(i == start) {
    			vector<TreeNode *> right = generateTrees_aux(start + 1, end);
    			for(int j = 0; j < right.size(); ++j) {
    				TreeNode *root = new TreeNode(i);
    				root->right = right[j];
    				result.push_back(root);
    			}
    		}
    		else if(i == end) {
    			vector<TreeNode *> left = generateTrees_aux(start, end - 1);
    			for(int j = 0; j < left.size(); ++j) {
    				TreeNode *root = new TreeNode(i);
    				root->left = left[j];
    				result.push_back(root);
    			}
    		}
    		else {
    			vector<TreeNode *> left = generateTrees_aux(start, i - 1);
    			vector<TreeNode *> right = generateTrees_aux(i + 1, end);
    			for(int j = 0; j < left.size(); ++j) {
    				for(int k = 0; k < right.size(); ++k) {
    					TreeNode *root = new TreeNode(i);
    					root->left = left[j];
    					root->right = right[k];
    					result.push_back(root);
    				}
    			}
    		}
    	}
    	return result;
    }
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector<TreeNode *> result = s->generateTrees(3);
	cout<<result.size()<<endl;
	return 0;
}