#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> phone_pad;
        phone_pad['2']= "abc";
        phone_pad['3']= "def";
        phone_pad['4']= "ghi";
        phone_pad['5']= "jkl";
        phone_pad['6']= "mno";
        phone_pad['7']= "pqrs";
        phone_pad['8']= "tuv";
        phone_pad['9']= "wxyz";
        
        vector<string> result;
        string current = phone_pad[digits[0]];
        if (digits.size() == 0) {
        	result.push_back("");
        	return result;
        }
        if (digits.size() == 1) {
        	for (int i = 0; i < current.size(); ++i) {
        		string tmp = "";
        		tmp.push_back(current[i]);
        		result.push_back(tmp);
        	}
        	return result;
        }
        string next = digits.substr(1, digits.size() - 1);
        vector<string> iter = letterCombinations(next);
        for (int i = 0; i < current.size(); ++i) {
        	for (int j = 0; j < iter.size(); ++j) {
        		string tmp = "";
        		tmp.push_back(current[i]);
        		result.push_back((tmp + iter[j]));
        	}
        }
        return result;


    }
};

int main(int argc, char const *argv[]) {
	Solution *s = new Solution();
	vector<string> result = s->letterCombinations("");
	for (int i = 0; i < result.size(); ++i) {
		cout<<result[i]<<", ";
	}
	cout<<endl;
	return 0;
}