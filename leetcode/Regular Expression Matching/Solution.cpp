#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
// this is a recursive solution
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
    	int repeat = 0;
        while (*s != '\0') {
        	if (*p == '\0') {
        		return false;
        	}
        	if (*p == '.') {
        		s++;
        		p++;
        	}
        	else if (*p == '*') {
        		if (*(p - 1) == '.' || *(p - 1) == *s) {
        			s++;
        			repeat++;
        			continue;
        		}
        		else {

        			if (*(p + 1) == *s) {//if (*(p + 1) == *s || *(p + 1) == '.'){
        				p++;
        				continue;
        			}

        			int MaxLength = repeat + 1;
        			bool match = false;
        			for (int i = 0; i <= MaxLength; i++) {
        				if (isMatch(s - i,p + 1)) {
        					match  = true;
        					break;
        				}
        			}
        			return match;
        		}
        	}
        	else if (*p == *s) {
        		s++;
        		p++;
        		repeat = 0;
        	}
        	else {
        		if (*(p + 1) == '*') {
        			p = p + 2;
        			repeat = 0;
        		}
        		else {
        			return false;
        		}
        	}
        }
        if (*p != '\0') {
        	if ( *p == '*') {
        		if (*(p + 1) == '\0') {
        			return true;
        		}
        		else {
        			int MaxLength = repeat+1;
        			bool match = false;
        			const char *temp = p+1;
        			for (int i = 0; i <= MaxLength; i++){
        				if(isMatch(s - i, temp)){
        					match = true;
        					break;
        				}
        			}
        			return match;
        		}
        	}
        	else { //*p!='*'
        		return ReEmpty(p);
        	}
        }
        return true;
    }
    bool ReEmpty(const char *p) { //check if this regular expr could match empty string
    	while (*p != '\0') {
        	if (*(p + 1) != '*') {
        		return false;
        	}
        	p = p + 2;
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
	Solution *s = new Solution();
	cout<<"aa, a:"<<(s->isMatch("aa", "a"))<<endl;
	cout<<"aa, aa:"<<(s->isMatch("aa", "aa"))<<endl;
	cout<<"aaa, aa:"<<(s->isMatch("aaa", "aa"))<<endl;
	cout<<"aa, a*:"<<(s->isMatch("aa", "a*"))<<endl;
	cout<<"aa, .*:"<<(s->isMatch("aa", ".*"))<<endl;
	cout<<"aab, c*a*b:"<<(s->isMatch("aab", "c*a*b"))<<endl;
	cout<<"ab, .*c:"<<(s->isMatch("ab", ".*c"))<<endl;
	cout<<"aaa, aaaa:"<<(s->isMatch("aaa", "aaaa"))<<endl;
	cout<<"abaaaa, a*ba*a*:"<<(s->isMatch("abaaaa", "a*ba*a*"))<<endl;
	cout<<"aaa, a*b:"<<(s->isMatch("aaa", "a*b"))<<endl;
	cout<<"aaa, a*aaaa:"<<(s->isMatch("aaa", "a*aaaa"))<<endl;
	cout<<"a, ab*:"<<(s->isMatch("a", "ab*"))<<endl;
	cout<<"abbbcd, ab*bbbcd:"<<(s->isMatch("abbbcd", "ab*bbbcd"))<<endl;
	cout<<"abbabaaaaaaacaa, a*.*b.a.*c*b*a*c*:"<<(s->isMatch("abbabaaaaaaacaa", "a*.*b.a.*c*b*a*c*"))<<endl;
	cout<<"bbbacbaacacaaaba, b*c*b*.a.*a*.*.*b*:"<<(s->isMatch("bbbacbaacacaaaba", "b*c*b*.a.*a*.*.*b*"))<<endl;

	return 0;
}