#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> result;
		if (n > 0) {
			generator(result, "", 0, 0, n);
		}
		return result;
    }
    void generator(vector<string> &result, string s, int l, int r, int n) {
    	if (l == n) {
    		result.push_back(s.append(n - r, ')'));
    		return;
    	}
    	generator(result, s + "(", l + 1, r, n);
    	if (l > r) {
    		generator(result, s + ")", l, r + 1, n);
    	}
    }
};

int main(int argc, char const *argv[]) {
	Solution *s = new Solution();
	vector<string> result = s->generateParenthesis(5);
	for (int i = 0; i < result.size(); ++i) {
		cout<<result[i]<<",";
	}
	cout<<endl;
	return 0;
}