#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//very ugly solution, wait to be improved
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        unordered_map<int, int> hashmap;
        for(int i = 0; i < S.size(); ++i) {
        	if(hashmap.find(S[i]) != hashmap.end()) {
        		hashmap[S[i]] = -1;
        	}
        	else {
        		hashmap[S[i]] = 1;
        	}
        }
        vector<vector<int> > result = subsetsWithDup_aux(S, hashmap);
        return result;
    }
    vector<vector<int> > subsetsWithDup_aux(vector<int> &S, unordered_map<int, int> &hashmap) {
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
        vector<vector<int> > previous = subsetsWithDup_aux(temp, hashmap);
        if(current != S[length - 2]) {
        	for(int i = 0; i < previous.size(); ++i) {
        		vector<int> t = previous[i];
        		result.push_back(t);     	
        		t.push_back(current);
        		result.push_back(t);
        	}
        }
        else {
        	for(int i = 0; i < previous.size(); ++i) {
        		vector<int> t = previous[i];
        		result.push_back(t);
        		int count = 0;
        		for(int j = 0; j < t.size(); ++j) {
        			if(t[j] == current) {
        				++count;
        			}
        		}
        		if(count == -(hashmap[current])) {
        			t.push_back(current);
        			result.push_back(t);
        		}
        	}
        	--hashmap[current];
        }
        
        return result;
    }
};
int main(int argc, char const *argv[])
{
	int data[] = {2, 2, 2};
	vector<int> S(data, data + 3);
	Solution *s = new Solution();
	vector<vector<int> > result = s->subsetsWithDup(S);
	for(int i = 0; i < result.size(); ++i) {
		cout<<"[";
		for(int j = 0; j < result[i].size(); ++j) {
			cout<<result[i][j]<<", ";
		}
		cout<<"]"<<endl;
	}
	return 0;
}