#include <stdio.h>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isNumber(const char *s) {
        int i = 0;
        bool hasDot = false;
        bool hasE = false;
        
        if( *s == ' ') {
        	bool hasNum = false;
        	while( *(s + i) != '\0') {
        		if( *(s + i) != ' ') {
        			hasNum = true;
        			break;
        		}
        		++i;
        	}
        	if(!hasNum) {
        		return false;
        	}
        }
        if( *(s + i) == '.') {
        	++i;
        	hasDot = true;
        	if( *(s + i) < '0' || *(s + i) > '9') {
        		return false;
        	}
        }
        if(*s == '\0') {
        	return false;
        }
        while (*(s + i) != '\0') {
        	if( *(s + i) >= '0' && *(s + i) <= '9') {
        		++i;
        	}
        	else if( *(s + i) == '.') {
        		if(hasDot) {
        			return false;
        		}
        		if( (*(s + i - 1) < '0' || *(s + i - 1) > '9') && (*(s + i + 1) < '0' || *(s + i + 1) > '9') && *(s + i + 1) != 'E' && *(s + i + 1) != 'e') {
        			return false;
        		}
        		if(hasE) {
        			return false;
        		}
        		hasDot = true;
        		++i;
        	}
        	else if( *(s + i) == 'e' || *(s + i) == 'E'){
        		if(hasE) {
        			return false;
        		}
        		if( ((*(s + i - 1) < '0' || *(s + i - 1) > '9') && *(s + i - 1) != '.') || ((*(s + i + 1) < '0' || *(s + i + 1) > '9') && *(s + i + 1) != '+' && *(s + i + 1) != '-')) {
        			return false;
        		}
        		hasE = true;
        		++i;
        	}
        	else if( *(s + i) == ' ') {
        		while( *(s + i) != '\0') {
        			if( *(s + i) != ' ') {
        				return false;
        			}
        			++i;
        		}
        	}
        	else if(*(s + i) == '-' || *(s + i) == '+') {
        		if(((*(s + i + 1) < '0' || *(s + i + 1) > '9') && *(s + i + 1) != '.') || (*(s + i - 1) >= '0' && *(s + i - 1) <= '9') ) {
        			return false;
        		}
        		++i;
        	}
        	else {
        		return false;
        	}
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
	const char *s1 = " 005047e+6";
	const char *s2 = "2e10";
	const char *s3 = "23e10";
	const char *s4 = "1 2";
	const char *s5 = "1.2";
	const char *s6 = "1..2";
	const char *s7 = "av3";
	Solution *s = new Solution();
	cout<<s->isNumber(s1)<<endl;
	return 0;
}