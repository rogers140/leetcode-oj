#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
    	int result = 0;
    	int index = 0;
        while (index < s.size()) {
        	switch (s[index]) {
        		case 'M':
        			result += 1000;
        			break;
        		case 'D':
        			result += 500;
        			break;
        		case 'C':
        			if ((index + 1 < s.size()) && (s[index + 1] == 'M')) {
        				result += 900;
        				++index;
        			}
        			else if ((index + 1 < s.size()) && (s[index + 1] == 'D')) {
        				result += 400;
        				++index;
        			}
        			else {
        				result += 100;
        			}
        			break;
        		case 'L':
        			result += 50;
        			break;
        		case 'X':
        			if ((index + 1 < s.size()) && (s[index + 1] == 'C')) {
        				result += 90;
        				++index;
        			}
        			else if ((index + 1 < s.size()) && (s[index + 1] == 'L')) {
        				result += 40;
        				++index;
        			}
        			else {
        				result += 10;
        			}
        			break;
        		case 'V':
        			result += 5;
        			break;
        		case 'I':
        			if ((index + 1 < s.size()) && (s[index + 1] == 'X')) {
        				result += 9;
        				++index;
        			}
        			else if ((index + 1 < s.size()) && (s[index + 1] == 'V')) {
        				result += 4;
        				++index;
        			}
        			else {
        				result += 1;
        			}
        			break;
        		default :
        			return 0;
        	}
        	++index;
        }
        return result;
    }
};

int main(int argc, char const *argv[]){
	Solution *s = new Solution();
	cout<<s->romanToInt("DCXXI")<<endl;
	return 0;
}