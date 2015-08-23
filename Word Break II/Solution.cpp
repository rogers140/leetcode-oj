#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		// record[i] stores all strings that can form from s.substr(i)
		if (s.empty()) return vector<string>();
		vector<vector<string> > record(s.size(), vector<string>());
		vector<bool> used(s.size(), false);
		wordBreak_aux(s, wordDict, record, used);
		return record[0];
	}
	void wordBreak_aux(string s, unordered_set<string>& wordDict,
		                 vector<vector<string> >& record, vector<bool>& used) {
		const int size = record.size();
		if (s.empty())
			return;
		for (int i = 1; i <= s.size(); ++i) {
			string curr = s.substr(0, i);
			string next = s.substr(i);
			//cout<<curr<<", "<<next<<endl;;
			if (wordDict.find(curr) != wordDict.end()) {
				if (i == s.size()) {
					record[size - s.size()].push_back(curr);
					//cout<<"Push back: "<<curr<<" to "<<size-s.size()<<endl;;
				} else if (!used[size - s.size() + i]) {
					wordBreak_aux(next, wordDict, record, used);
					for (int j = 0; j < record[size - s.size() + i].size(); ++j) {
					  record[size - s.size()].push_back(curr + " " + record[size - s.size() + i][j]);
					  //cout<<"Push back: "<<curr + " " + record[size - s.size() + i][j]<<" to "<<size-s.size()<<endl;
				  }
				} else if (used[size - s.size() + i]) {
					for (int j = 0; j < record[size - s.size() + i].size(); ++j) {
					  record[size - s.size()].push_back(curr + " " + record[size - s.size() + i][j]);
					  //cout<<"Push back: "<<curr + " " + record[size - s.size() + i][j]<<" to "<<size-s.size()<<endl;
				  }
				}
			}
		}
		used[size - s.size()] = true;
	}
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	unordered_set<string> wordDict1 = {"a", "b", "ab"};
	string str1 = "ab";

	unordered_set<string> wordDict2 = {"cat","cats","and","sand","dog"};
  string str2 = "";

  vector<string> result = s->wordBreak(str2, wordDict2);
  for (string s : result) {
  	cout<<s<<endl;
  }
	return 0;
}