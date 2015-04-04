#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
    	vector<int> row(n, 0);
        vector<vector<int> > matrix(n, row);
        int leftBoarder = 0;
        int rightBoarder = n - 1;
        int topBoarder = 0;
        int bottomBoarder = n - 1;
        char direction = 'r';
        int step = 0;
        int rowIndex = 0; 
        int colIndex = 0;
        int value = 1;
        while(step < n * n) {
        	
        	switch(direction) {
        		case 'r':
        			if(colIndex < rightBoarder) {
        				matrix[rowIndex][colIndex] = value;
        				++step;
        				++colIndex;
        				++value;
        			}
        			else if(colIndex == rightBoarder) {
        				matrix[rowIndex][colIndex] = value;
        				++step;
        				++rowIndex;
        				direction = 'd';//begin to move down
        				++topBoarder; // topBoarder moves down
        				++value;
        			}
        			break;
        		case 'd':
        			if(rowIndex < bottomBoarder) {
        				matrix[rowIndex][colIndex] = value;
        				++step;
        				++rowIndex;
        				++value;
        			}
        			else if(rowIndex == bottomBoarder) {
        				matrix[rowIndex][colIndex] = value;
        				++step;
        				--colIndex;
        				direction = 'l';//begin to move left
        				--rightBoarder;
        				++value;
        			}
        			break;
        		case 'l':
        			if(colIndex > leftBoarder) {
        				matrix[rowIndex][colIndex] = value;
        				++step;
        				--colIndex;
        				++value;
        			}
        			else if(colIndex == leftBoarder) {
        				matrix[rowIndex][colIndex] = value;
        				++step;
        				--rowIndex;
        				direction = 'u';//begin to move up
        				--bottomBoarder;
        				++value;
        			}
        			break;
        		case 'u':
        			if(rowIndex > topBoarder) {
        				matrix[rowIndex][colIndex] = value;
        				++step;
        				--rowIndex;
        				++value;
        			}
        			else if(rowIndex == topBoarder) {
        				matrix[rowIndex][colIndex] = value;
        				++step;
        				++colIndex;
        				direction = 'r';
        				++leftBoarder;
        				++value;
        			}
        			break;
                default:
                    return matrix;
        	}
        }
        return matrix;

    }
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector<vector<int> > matrix = s->generateMatrix(0);
	for(int i = 0; i < matrix.size(); ++i) {
		for(int j = 0; j <matrix[i].size(); ++j) {
			cout<<matrix[i][j]<<", ";
		}
		cout<<endl;
	}
	return 0;
}