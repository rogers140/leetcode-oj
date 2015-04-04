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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        if(root == NULL) {       
            return result;
        }
        else if(root->left == NULL && root->right == NULL) { //leaf
            if(sum == root->val) {
                vector<int> route;
                route.push_back(root->val);
                result.push_back(route);
                return result;
            }
            else {
                return result;
            }
        }
        else if(root->left == NULL) {
            vector<vector<int> > previousResult = pathSum(root->right, sum - root->val);
            for(int i = 0; i < previousResult.size(); ++i) {
                vector<int> tmp = previousResult[i];
                tmp.insert(tmp.begin(), root->val);
                result.push_back(tmp);
            }
        }
        else if(root->right == NULL) {
            vector<vector<int> > previousResult = pathSum(root->left, sum - root->val);
            for(int i = 0; i < previousResult.size(); ++i) {
                vector<int> tmp = previousResult[i];
                tmp.insert(tmp.begin(), root->val);
                result.push_back(tmp);
            }
        }
        else {
            vector<vector<int> > previousLeft = pathSum(root->left, sum - root->val);
            vector<vector<int> > previousRight = pathSum(root->right, sum - root->val);
            vector<vector<int> > previousResult;
            previousResult.reserve(previousLeft.size() + previousRight.size());
            previousResult.insert(previousResult.end(), previousLeft.begin(), previousLeft.end());
            previousResult.insert(previousResult.end(), previousRight.begin(), previousRight.end());
            for(int i = 0; i < previousResult.size(); ++i) {
                vector<int> tmp = previousResult[i];
                tmp.insert(tmp.begin(), root->val);
                result.push_back(tmp);
            }
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	TreeNode *root = new TreeNode(1);
	TreeNode *node1 = new TreeNode(2);
	root->left = node1;
    vector<vector<int> > result = s->pathSum(root, 3);
    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < result[i].size(); ++j) {
            cout<<result[i][j]<<",";
        }
        cout<<endl;
    }
	return 0;
}