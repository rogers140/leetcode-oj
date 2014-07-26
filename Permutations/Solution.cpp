#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size() == 0) {
        	return result;
        }
        if(num.size() == 1) {
        	result.push_back(num);
        	return result;
        }
        int length = num.size();
        for(int i = length - 1; i >= 0;--i) {
        	vector<vector<int> > nextPermutation;
        	vector<int> temp(num);
        	int currentNumber = num[i];
        	temp.erase(temp.begin() + i);
        	nextPermutation = permute(temp);
        	for(int j = 0; j < nextPermutation.size(); ++j) {
        		nextPermutation[j].push_back(currentNumber);
        		vector<int> temp_result = nextPermutation[j];
        		result.push_back(temp_result);
        	}
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	vector<vector<int> > result = s->permute(num);
	for(int i = 0; i < result.size(); ++i) {
		for(int j = 0; j < result[i].size(); ++j) {
			cout<<result[i][j]<<", ";
		}
		cout<<endl;
	}
	return 0;
}