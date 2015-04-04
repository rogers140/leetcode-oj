#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
    	string result = "";
    	if (strs.size() == 0) {
    		return result;
    	}
    	else {
    		result = strs[0];
    	}
    	for (int i = 1; i < strs.size(); ++i) {
    		result = prefixOfTwo(result, strs[i]);
    	}
        return result;
    }
    string prefixOfTwo(string str1, string str2) {
    	int size = (str1.size() < str2.size()) ? str1.size() : str2.size();
    	string ret = "";
    	for (int i = 0; i < size; ++i) {
    		if (str1[i] == str2[i]) {
    			ret += str1[i];
    		}
    		else{
    			break;
    		}
    	}
    	return ret;
    }
};

int main(int argc, char const *argv[]) {
	Solution *s = new Solution();
	vector<string> str;
	str.push_back("goodmorning");
	str.push_back("goodevening");
	str.push_back("google");
	str.push_back("goohoo");
	str.push_back("goodboy");
	cout << s->longestCommonPrefix(str) << endl; 
	return 0;
}