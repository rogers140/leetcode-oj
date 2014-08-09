#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
/*
f[m][n] is a matrix store the min value of every location we can get.
f[0][0] =grid[0][0], f[i][0]=f[i-1][0]+grid[i][0], f[0][j]=f[0][j-1]+grid[0][j]
f[i][j]=min(f[i-1][j],f[i][j-1])+grid[i][j].
at last return the f[m-1][n-1]

to reduce the memory, Assume that you are populating the table row by row, the current value (f[i][j]) will 
be used immediately in the calculation of f[i][j+1], so there is no need to store all the previous column values.
*/
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();

        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dp[j + 1] = min(dp[j + 1], dp[j]) + grid[i][j];

        return dp.back();
    }
};

int main(int argc, char const *argv[])
{
	
	return 0;
}