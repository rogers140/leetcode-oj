#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
    	if(s1.size() != s2.size()) {
    		return false;
    	}
        int length = s1.size();
        if(s1 == s2) {
        	return true;
        }
        for(int i = 1; i < length; ++i) {
        	string s11 = s1.substr(0, i);
            string s12 = s1.substr(i, length - i);
            string s21 = s2.substr(0, i);
            string s22 = s2.substr(i, length - i);
            string s23 = s2.substr(length - i, i);
            string s24 = s2.substr(0, length - i);
            if((isAnagram(s11, s21) && isAnagram(s12, s22) && isScramble(s11, s21) && isScramble(s12, s22)) ||
            	(isAnagram(s11, s23) && isAnagram(s12, s24) && isScramble(s11, s23) && isScramble(s12, s24))){
                return true;
            }
        }
        return false;
    }
    bool isAnagram(string s1, string s2) {
    	sort(s1.begin(), s1.end());
    	sort(s2.begin(), s2.end());
    	if(s1 == s2) {
    		return true;
    	}
    	else {
    		return false;
    	}
    }
};
int main(int argc, char const *argv[])
{
	string s1 = "abab";
	string s2 = "aabb";
	Solution *s = new Solution();
	cout<<s->isScramble(s1, s2)<<endl;
	return 0;
}