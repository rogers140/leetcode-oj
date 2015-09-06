#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
// this is a recursive solution
class Solution {
public:
    bool findMatch(string &s, string &p, int pos_s, int pos_p) {
        if (pos_s == -1 && pos_p == -1) {
            return true;
        } 
        if (pos_p== -1 || pos_s < -1) {
            return false;
        }
        if (p[pos_p] == '.') {
            return findMatch(s, p, pos_s-1, pos_p-1);
        } else if (p[pos_p] == '*') {
            //match zero element
            if (findMatch(s, p, pos_s, pos_p - 2)) return true;
            for (int i = pos_s; i>=0 && (p[pos_p-1] =='.' || s[i] == p[pos_p-1]); i--) {
                if (findMatch(s, p, i - 1, pos_p - 2)) return true;
            }
            return false;
        } else {
            // match single element
            return ((s[pos_s] == p[pos_p]) && findMatch(s, p, pos_s-1, pos_p-1)); 
        }
    }
    bool isMatch(string s, string p) {
        int len_s = s.size();
        int len_p = p.size();
        return findMatch(s, p, len_s - 1, len_p - 1);
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