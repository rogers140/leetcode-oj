#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
    	vector<string> vec,anavec;
    	unordered_map<string,vector<string> > mp;
        for(string s : strs){                    //sort every string and store groups of strings that are anagrams in a map
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(s);
        }
        for(auto map : mp){                      // find all anagrams
            if(map.second.size() > 1)
            	vec.insert(vec.end(), map.second.begin(), map.second.end());
        }
        return vec;
    }
};
int main(int argc, char const *argv[])
{
	string str1 = "asrp";
	string str2 = "aasprt";
	string str3 = "rasp";
	string str4 = "aas";
	string str5 = "ssaa";
	Solution *s = new Solution();
	vector<string> strs;
	strs.push_back(str1);
	strs.push_back(str2);
	strs.push_back(str3);
	strs.push_back(str4);
	strs.push_back(str5);
	vector<string> result = s->anagrams(strs);
	for(int i = 0; i < result.size(); ++i) {
		cout<<result[i]<<",";
	}
	cout<<endl;

	return 0;
}