#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		return combinationSumPlus(candidates, target, candidates.size() - 1);
	}
    vector<vector<int> > combinationSumPlus(vector<int> &candidates, int target, int current) {
    	vector<vector<int> > result_set;
    	int length = candidates.size();
        for (int i = current; i >= 0; --i) {
        	if (candidates[i] == target) {
        		vector<int> result;
        		result.push_back(candidates[i]);
        		result_set.push_back(result);
        	}
        	else if (candidates[i] > target) {
        		continue;
        	}
        	else {
        		vector<vector<int> > previous_set = combinationSumPlus(candidates, target - candidates[i], i);
        		if (previous_set.size() == 0) {
        			continue;
        		}
        		else {
        			for (int j = 0; j < previous_set.size(); ++j) {
        				previous_set[j].push_back(candidates[i]);
        				result_set.push_back(previous_set[j]);
        			}
        		}    		
        	}      	
        }
    	return result_set;
    }
};
int main(int argc, char const *argv[])
{
	vector<int> candidates(4, 0);
	candidates[0] = 8;
	candidates[1] = 7;
	candidates[2] = 4;
	candidates[3] = 3;
	Solution *s = new Solution();
	vector<vector<int> > result_set = s->combinationSum(candidates, 11);
	cout<<result_set[2][0]<<endl;
	return 0;
}