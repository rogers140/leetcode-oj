#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        unordered_map<int, int> exist;
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
        	if(exist.find(currentNumber) != exist.end()) {
        		continue;
        	}
        	else {
        		exist[currentNumber] = 1;
        	}
        	temp.erase(temp.begin() + i);
        	nextPermutation = permuteUnique(temp);
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
	num.push_back(1);
	num.push_back(3);
	vector<vector<int> > result = s->permuteUnique(num);
	for(int i = 0; i < result.size(); ++i) {
		for(int j = 0; j < result[i].size(); ++j) {
			cout<<result[i][j]<<", ";
		}
		cout<<endl;
	}
	return 0;
}