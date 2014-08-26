#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
    	sort(S.begin(), S.end());
        int length = S.size();
        vector<vector<int> > result;
        if(length == 0) {
        	vector<int> empty;//still need empty set
        	result.push_back(empty); 
        	return result;
        }
        if(length == 1) {
        	vector<int> temp1;
        	vector<int> temp2;
        	temp2.push_back(S[0]);
        	result.push_back(temp1);
        	result.push_back(temp2);
        	return result;
        }
        vector<int> temp(S);
        int current = S[length - 1];
        temp.pop_back();
        vector<vector<int> > previous = subsets(temp);
        for(int i = 0; i < previous.size(); ++i) {
        	vector<int> t = previous[i];
        	result.push_back(t);
        	t.push_back(current);
        	result.push_back(t);
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
	int data[] = {4, 1, 0};
	vector<int> S(data, data + 3);
	Solution *s = new Solution();
	vector<vector<int> > result = s->subsets(S);
	for(int i = 0; i < result.size(); ++i) {
		cout<<"[";
		for(int j = 0; j < result[i].size(); ++j) {
			cout<<result[i][j]<<", ";
		}
		cout<<"]"<<endl;
	}
	return 0;
}