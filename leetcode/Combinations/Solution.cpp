#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> array;
        for(int i = 1; i <= n; ++i) {
        	array.push_back(i);
        }
        return combine_aux(array, k);
    }
    vector<vector<int> > combine_aux(vector<int> &array, int k) {
    	vector<vector<int> > result;
        if(k == 1) {
        	for(int i = 1; i <= array.size(); ++i) {
        		vector<int> temp;
        		temp.push_back(i);
        		result.push_back(temp);
        	}
        	return result;
        }
        if(k == array.size()) {
        	result.push_back(array);
        	return result;
        }
        vector<int> temp(array);
        for(int i = array.size() - 1; i >= k - 1; --i) {
        	int current = array[i];
        	temp.pop_back();
        	vector<vector<int> > next = combine_aux(temp, k - 1);
        	for(int j = 0; j < next.size(); ++j) {
        		vector<int> t = next[j];
        		t.push_back(current);
        		result.push_back(t);
        	}
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector<vector<int> > result = s->combine(4, 3);
	for(int i = 0; i < result.size(); ++i) {
		cout<<"[";
		for(int j = 0; j < result[i].size(); ++j) {
			cout<<result[i][j]<<", ";
		}
		cout<<"]"<<endl;
	}
	return 0;
}