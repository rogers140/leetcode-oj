#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	int n = s1.size();
    	int m = s2.size();
    	if(m + n != s3.size()) {
    		return false;
    	}
        vector<bool> row(m + 1, false);
        vector<vector<bool> > dp(n + 1, row);//build the dp map
        //we use dp[i][j] to represent whether s1.substr(0, i) and s2.substr(0, j)
        //could represent s3.substr(0, i + j)
        dp[0][0] = true;
        for(int i = 0; i <= n; ++i) {
        	for(int j = 0; j <= m; ++j) {
        		if(i > 0) {
        			//try if s1 could provide this char
        			dp[i][j] = dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]); 
        		}
        		if(j > 0) {
        			//try if s2 could provide this char in case s1 could not
        			dp[i][j] = dp[i][j] || (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
        		}
        	}
        }
        return dp[n][m];
    }
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	cout<<s->isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa", 
		"babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab", 
		"babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab")<<endl;
	return 0;
}