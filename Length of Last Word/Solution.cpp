#include <stdio.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(const char *s) {
    	if(s == NULL) {
    		return 0;
    	}
        int length = 0;
        int ptr = 0;
        while(s[ptr] != '\0') {
        	if(s[ptr] == ' ' && s[ptr + 1] != ' ' && s[ptr + 1] != '\0') {
        		length = 0;
        	}
        	else if(s[ptr] != ' '){
        		++length;
        	}
        	++ptr;
        }
        return length;
    }
};
int main(int argc, char const *argv[])
{
	Solution *solution = new Solution();
	const char *s = " a   ";
	cout<<solution->lengthOfLastWord(s)<<endl;
	return 0;
}