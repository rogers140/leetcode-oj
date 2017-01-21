#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Represents the number of paths reaching the position [i-1] of the current row
        vector<int> array(obstacleGrid[0].size() + 1, 0);
        array[1] = 1;
        for(int i = 0; i < obstacleGrid.size(); ++i) {
        	for(int j = 1; j <= obstacleGrid[0].size(); ++j) {
        		if(obstacleGrid[i][j - 1] == 0) {
        			array[j] += array[j - 1];
        		}
        		else {
        			array[j] = 0;
        		}
        	}
        }
        return array[obstacleGrid[0].size()];

    }
};
int main(int argc, char const *argv[])
{
	vector<int> row(3, 0);
	vector<vector<int> > obstacleGrid(3, row);
	obstacleGrid[1][1] = 1;
	for(int i = 0; i < obstacleGrid.size(); ++i) {
		for(int j = 0; j < obstacleGrid[i].size(); ++j) {
			cout<<obstacleGrid[i][j]<<", ";
		}
		cout<<endl;
	}
	Solution *s = new Solution();
	cout<<s->uniquePathsWithObstacles(obstacleGrid)<<endl;
	return 0;
}