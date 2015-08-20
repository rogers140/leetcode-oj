#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<string> > partition(string s) {
		vector<vector<string> > result;
		if (s.empty()) return result;
		vector<string> current_result;
		partition_aux(result, s, current_result);
		return result;
	}
	void partition_aux(vector<vector<string> >& result, string s, vector<string>& current_result) {
		if (s.empty()) {
			vector<string> new_result(current_result);
			result.push_back(new_result);
		}
		for (int i = 0; i < s.size(); ++i) {
			if (isPalindrom(s.substr(0, i + 1))) {
				current_result.push_back(s.substr(0, i + 1));
				partition_aux(result, s.substr(i + 1), current_result);
				current_result.pop_back();
			}
		}
	}
	bool isPalindrom(string s) {
		string temp(s);
		reverse(s.begin(), s.end());
		if (s == temp) return true;
		return false;
	}

};
int main(int argc, char const* argv[]) {
	Solution *s = new Solution();
	string s1 = "aaba";
	string s2 = "abcdcbacbca";
	vector<vector<string> > result = s->partition(s2);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j) {
			cout<<result[i][j]<<", ";
		}
		cout<<endl;
	}
}