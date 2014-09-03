#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
//each cell in the ip address should not begin with 0 except only 0
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        for(int i = 1; i <= 3; ++i) {
        	for(int j = i + 1; j <= i + 3; ++j) {
        		for(int k = j + 1; k <= j + 3; ++k) {
        			if(k >= s.size()) {
        				continue;
        			}
        			string s1 = s.substr(0, i);
        			string s2 = s.substr(i, j - i);
        			string s3 = s.substr(j, k - j);
        			string s4 = s.substr(k, s.size() - k);
        			if(isValidCell(s1) && isValidCell(s2) && isValidCell(s3) && isValidCell(s4)) {
        				string current = s1 + "." + s2 + "." + s3+ "." + s4;
        				result.push_back(current);
        			}
        		}
        	}
        }
        return result;
    }
    bool isValidCell(string s) {
    	if(s[0] == '0' && s != "0") {
    		return false;
    	}
    	int c = atoi(s.c_str());
    	if(c > 255) {
    		return false;
    	}
    	return true;
    }
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector<string> result = s->restoreIpAddresses("103574606193");
	for(int i = 0; i < result.size(); ++i) {
		cout<<result[i]<<endl;
	}
	return 0;
}