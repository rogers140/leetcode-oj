#include <stdio.h>
#include <iostream>
using namespace std;
//这道题目的关键是对于*的处理。
//如果考虑是移动patter的指针，是很难操作的。
//所以换一种思维，去移动sequence的指针，去比对被*切断的部分，才比较方便。
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(s[0] == '\0' && p[0] == '\0') {
        	return true;
        }
        if(s[0] == '\0') {
        	if(p[0] == '*') {
        		return isMatch(s, p + 1);
        	}
        	else {
        		return false;
        	}
        }
        // cout<<ptr1<<","<<ptr2<<endl;
        	
        if(p[0] == '?' || s[0] == p[0]) {
        	return isMatch(s + 1, p + 1);
        }
        else if(p[0] == '*') {
        	while(p[0] == '*') {
        		p++;
        	}
        	if(p[0] == '\0') return true;
        	int n = 0;
        	while(p[n] != '\0' && p[n] != '*') {//measure the length of non star sequence
        		++n;
        	}
        	while(s[0] != '\0') {
        		if(s[n - 1] == '\0') return false;
        		int i = 0;
        		for(; i < n; ++i) {
        			if(s[i] != p[i] && p[i] != '?') {
        				break;
        			}
        		} 
        		if(i == n) {
        			if(p[n] == '*') {
        				return isMatch(s + n, p + n);
        			}
        			else {
        				if(s[n] == '\0') return true;
        				else s++; //let s move forward to match
        			}
        		}
        		else {
        			s++;
        		}
        	}
        }
        else {
        	return false;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	cout<<s->isMatch("aa", "*")<<endl;
	return 0;
}