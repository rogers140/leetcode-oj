#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numDistinct(string S, string T) {
    	if(S.length() == 0)
    		return 0;
    	if(T.length() == 0)
    		return 1;
        //use dp
    	vector<vector<int> > matrix(S.length() + 1, vector<int>(T.length() + 1, 0));
    	for(int i = 0; i < S.length() + 1; ++i){
    		matrix[i][0] = 1;
    	}
    	for(int j = 1; j < T.length() + 1; ++j){
    		for(int i = j; i < S.length() + 1; ++i){
    			if(S[i - 1] == T[j - 1]){
    				//choose S[i] as the last element + not choose S[i] as the last element
    				matrix[i][j] = matrix[i - 1][j - 1] + matrix[i - 1][j];
    			}
    			else{
    				matrix[i][j] = matrix[i - 1][j];
    			}
    		}
    	}
    	return matrix[S.length()][T.length()];

    }
};
int main(int argc, char const *argv[])
{
	string S = "a";
	string T = "b";
	Solution *s = new Solution();
	cout<<s->numDistinct(S, T)<<endl;
	return 0;
}