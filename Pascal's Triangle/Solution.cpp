#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        for(int i = 1; i <= numRows; ++i) {
            vector<int> row;
            for(int j = 1; j <= i; ++j) {
                row.push_back(1);
            }
            result.push_back(row);
        }
        for(int i = 1; i < numRows; ++i) {
            for(int j = 0; j < result[i - 1].size(); ++j) {
                if(j - 1 >= 0 && j < result[i].size()) {
                    result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
                }
            }
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
    Solution *s = new Solution();
    vector<vector<int> > result = s->generate(3);
    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < result[i].size(); ++j) {
            cout<<result[i][j]<<",";
        }
        cout<<endl;
    }
    return 0;
}

