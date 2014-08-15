#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
//Levenshtein Distance Algorithm
class Solution {
public:
    int minDistance(string word1, string word2) {
    	int m = word1.size();
    	int n = word2.size();
        if(m == 0) {
        	return n;
        }
        if(n == 0) {
        	return m;
        }
        vector<int> row(m + 1, 0);
        vector<vector<int> > matrix(n + 1, row);
        for(int j = 0; j < m + 1; ++j) {
        	matrix[0][j] = j;
        }
        for(int i = 0; i < n + 1; ++i) {
        	matrix[i][0] = i;
        }
        for(int i = 1; i < n + 1; ++i) {
        	for(int j = 1; j < m + 1; ++j) {
        		int temp;
        		if(word2[i - 1] == word1[j - 1]) {
        			temp = 0;
        		}
        		else {
        			temp = 1;
        		}
        		matrix[i][j] = min(matrix[i - 1][j] + 1, min(matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + temp));
        	}
        }
        return matrix[n][m];
    }
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	cout<<s->minDistance("hello", "helloworld")<<endl;
	return 0;
}