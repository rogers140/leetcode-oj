#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int> > temp = combinationSum2Plus(candidates, target, candidates.size() - 1);
        vector<vector<int> > result_set;

        int length = temp.size();
        for (int i = 0; i < length - 1; ++i) {
            bool dumb = false;
            for (int j = i + 1; j < temp.size(); ++j) {
                if (temp[i] == temp[j]) {
                    dumb = true;
                    break;
                }
            } 
            if(!dumb) {
                result_set.push_back(temp[i]);
            }
        }
        if (temp.size() > 0) {
            result_set.push_back(temp[temp.size() - 1]);
        }      
        return result_set;
	}
    vector<vector<int> > combinationSum2Plus(vector<int> &candidates, int target, int current) {
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
                if (i - 1 >= 0) {
                    vector<vector<int> > previous_set = combinationSum2Plus(candidates, target - candidates[i], i - 1);
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
        }
    	return result_set;
    }
};
int main(int argc, char const *argv[])
{
	vector<int> candidates(7, 0);
	candidates[0] = 10;
	candidates[1] = 1;
	candidates[2] = 2;
	candidates[3] = 7;
    candidates[4] = 6;
    candidates[5] = 1;
    candidates[6] = 5;

    // vector<int> candidates(1, 0);
    // candidates[0] = 2;

	Solution *s = new Solution();
	vector<vector<int> > result_set = s->combinationSum2(candidates, 8);
    for (int i = 0; i < result_set.size(); ++i) {
        for (int j = 0; j < result_set[i].size(); ++j) {
            cout<<result_set[i][j]<<",";
        }
        cout<<endl;
    }
	return 0;
}