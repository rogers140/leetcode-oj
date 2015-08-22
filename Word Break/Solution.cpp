#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  bool wordBreak(string s, unordered_set<string>& wordDict) {
  	vector<int> record(s.size(), 0);  // 0 is not used, 1 s.substr(i) is true, -1 is false
  	return wordBreak_aux(s, wordDict, record);
  }
  bool wordBreak_aux(string s, unordered_set<string>& wordDict, vector<int>& record) {
    if (s.empty()) return true;
  	for (int i = 1; i <= s.size(); ++i) {
  		if (wordDict.find(s.substr(0, i)) != wordDict.end()) {
        if (record[i] == 0) {
        	if(wordBreak_aux(s.substr(i), wordDict, record)) {
        		record[i] = 1;
        	} else {
        		record[i] = -1;
        	}
        }
        if (record[i] == 1) return true;
  		}
  	}
  	return false;
  }
};
int main(int argc, char const *argv[])
{
	unordered_set<string> wordDict1 = {"a","aa","aaa","aaaa",
	                                  "aaaaa","aaaaaa","aaaaaaa",
	                                  "aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
	Solution *s = new Solution();
	string str1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	//cout<<s->wordBreak(str1, wordDict1)<<endl;

  unordered_set<string> wordDict2 = {"a", "b"};
  string str2 = "ab";
  cout<<s->wordBreak(str2, wordDict2)<<endl;
	return 0;
}