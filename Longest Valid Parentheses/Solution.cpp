#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
  // struct Info
  //   {
  //     Info(char u, int p, int vp, int vl) 
  //       : c(u), pos(p), last_valid_pos(vp), last_valid_len(vl){};
  //     char c;
  //     int pos;
  //     int last_valid_pos;
  //     int last_valid_len;
  //   };
  //   //the main problem is to decide when to combine valid substring.
  //   int longestValidParentheses(string s) {
  //       if (s.size() == 0)
  //           return 0;

  //       int max_len = 0;
  //       int last_valid_len = 0;
  //       int last_valid_pos = -1;

  //       stack <Info> stk;

  //       for (int i = 0; i < s.size(); ++i) {
  //           if (stk.empty() || stk.top().c == s[i] || (stk.top().c == ')' && s[i] == '(')) {
  //               stk.push(Info(s[i], i, last_valid_pos, last_valid_len));
  //           } 
  //           else {
  //               Info top = stk.top();
  //               stk.pop();
  //               int n = i - top.pos + 1;
  //               if (top.last_valid_pos + 1 == top.pos) {//key point
  //                   last_valid_len = top.last_valid_len + n;
  //                   last_valid_pos = i;
  //                   max_len = (last_valid_len > max_len ? last_valid_len : max_len);
  //               }
  //               else {
  //                   max_len = (max_len < n ? n : max_len);
  //                   last_valid_len = n;
  //                   last_valid_pos = i;
  //               }
  //           }
  //       }
  //       return max_len;
  //   }
  int longestValidParentheses(string s) {
    int longest = 0;
    int extra=0;
    int length=0;
    for (int i=0; i<s.size(); i++) {
      // Forward pass
      if (s[i] == '(') {
        extra++;
        length++;
      } else {
        if (extra>0) {
          extra--;
          length++;
          if(extra == 0)
            longest = max(longest, length);
        } else {
          extra = 0;
          length=0;
        }
      }
    }
    length = 0;
    extra=0;
    for (int i=s.size()-1; i>=0; i--) {
      // Backward pass
      if (s[i] == ')') {
        extra++;
        length++;
      } else {
        if(extra>0){
          extra--;
          length++;
          if(extra == 0)
            longest = max(longest, length);
          } else {
            extra = 0;
            length=0;
          }
        }
    }
    return longest;
  }
};

int main(int argc, char const *argv[]) {
	string s1 = ")()())";
	string s2 = ")()(((())))(";
	string s3 = ")(((((()())()()))()(()))(";
	string s4 = "()(()";
	string s5 = "(()(((()";
	Solution *s = new Solution();
	cout<<"s1: "<<s->longestValidParentheses(s1)<<endl;
	cout<<"s2: "<<s->longestValidParentheses(s2)<<endl;
	cout<<"s3: "<<s->longestValidParentheses(s3)<<endl;
	cout<<"s4: "<<s->longestValidParentheses(s4)<<endl;
	cout<<"s5: "<<s->longestValidParentheses(s5)<<endl;
	return 0;
}