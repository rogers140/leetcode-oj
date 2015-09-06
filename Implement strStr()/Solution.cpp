#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0) return 0;
    if (haystack.size() == 0) return -1;
    vector<int> next(needle.size(), 0);
    computeNext(next, needle);
    int i = 0;
    int j = 0;
    const int haystack_size = haystack.size();
    const int needle_size = needle.size();
    while (i < haystack_size && j < needle_size) {
      if (j == -1 || haystack[i] == needle[j]) {
        ++i;
        ++j;
      } else {
        j = next[j];
      }
    }
    if (j == needle.size()) return (i - j);
    else return -1;
  }
  void computeNext(vector<int>& next, const string& needle) {
    if (next.empty()) return;
    next[0] = -1;
    int preIndex = -1;
    int postIndex = 0;
    while (postIndex < next.size() - 1) {
      if (preIndex == -1 || needle[postIndex] == needle[preIndex]) {
        ++preIndex;
        ++postIndex;
        next[postIndex] = preIndex;
      } else {
        preIndex = next[preIndex];
      }
    }
  }
};
int main(int argc, char const *argv[]) {
  Solution *s = new Solution();
  cout<<s->strStr("mississippi", "issi")<<endl;
	return 0;
}

