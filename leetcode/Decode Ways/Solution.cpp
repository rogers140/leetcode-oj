#include <stdio.h>
#include <iostream>
using namespace std;
//if use recursive method, it will generate TLE
//so we use DP instead
class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0') {
        	return 0;
        }
/*
        if(s.size() == 2) {
        	if(s > "26") {
        		return 1;
        	}
        	else {
        		return 2;
        	}
        }

        string head = s.substr(0, 2);
        int result = 0;
        if(head > "26") {
        	result = numDecodings(s.substr(1, s.size() - 1));
        } 
        else {
        	result = numDecodings(s.substr(1, s.size() - 1)) + numDecodings(s.substr(2, s.size() - 2));;
        }
*/
        int cur_2 = 1, cur_1 = 1, cur = 0;
        for(int i = 2; i <= s.size(); ++i) {
        	if(s[i - 1] != '0') {
        		cur += cur_1;
        	}
        	if(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7')) {
        		cur += cur_2;
        	}
        	cur_2 = cur_1;
        	cur_1 = cur;
        	cur = 0;
        }
        return cur_1;
    }
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	cout<<s->numDecodings("9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253")<<endl;
	return 0;
}