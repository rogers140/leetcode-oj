#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
    	vector<int> result;
    	int totalRow = matrix.size();
    	if(totalRow == 0) {
    		return result;
    	}
    	int totalCol = matrix[0].size();
    	if(totalCol == 0) {
    		return result;
    	}
        int leftBoarder = 0;
        int rightBoarder = totalCol - 1;
        int topBoarder = 0;
        int bottomBoarder = totalRow - 1;
        char direction = 'r';

        int step = 0;
        int rowIndex = 0; 
        int colIndex = 0;
        while(step < totalRow * totalCol) {
        	
        	switch(direction) {
        		case 'r':
        			if(colIndex < rightBoarder) {
        				result.push_back(matrix[rowIndex][colIndex]);
        				++step;
        				++colIndex;
        			}
        			else if(colIndex == rightBoarder) {
        				result.push_back(matrix[rowIndex][colIndex]);
        				++step;
        				++rowIndex;
        				direction = 'd';//begin to move down
        				++topBoarder; // topBoarder moves down
        			}
        			break;
        		case 'd':
        			if(rowIndex < bottomBoarder) {
        				result.push_back(matrix[rowIndex][colIndex]);
        				++step;
        				++rowIndex;
        			}
        			else if(rowIndex == bottomBoarder) {
        				result.push_back(matrix[rowIndex][colIndex]);
        				++step;
        				--colIndex;
        				direction = 'l';//begin to move left
        				--rightBoarder;
        			}
        			break;
        		case 'l':
        			if(colIndex > leftBoarder) {
        				result.push_back(matrix[rowIndex][colIndex]);
        				++step;
        				--colIndex;
        			}
        			else if(colIndex == leftBoarder) {
        				result.push_back(matrix[rowIndex][colIndex]);
        				++step;
        				--rowIndex;
        				direction = 'u';//begin to move up
        				--bottomBoarder;
        			}
        			break;
        		case 'u':
        			if(rowIndex > topBoarder) {
        				result.push_back(matrix[rowIndex][colIndex]);
        				++step;
        				--rowIndex;
        			}
        			else if(rowIndex == topBoarder) {
        				result.push_back(matrix[rowIndex][colIndex]);
        				++step;
        				++colIndex;
        				direction = 'r';
        				++leftBoarder;
        			}
        			break;
                default:
                    return result;
        	}
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
	vector<int> row1;
	vector<int> row2;
	vector<int> row3;
	vector<int> row4;

	row1.push_back(1);
	row1.push_back(2);
	row1.push_back(3);

	row2.push_back(4);
	row2.push_back(5);
	row2.push_back(6);

	row3.push_back(7);
	row3.push_back(8);
	row3.push_back(9);

	vector<vector<int> > matrix;
	matrix.push_back(row1);
	matrix.push_back(row2);
	matrix.push_back(row3);

	Solution *s = new Solution();
	vector<int> result = s->spiralOrder(matrix);
	for(int i = 0; i < result.size(); ++i) {
		cout<<result[i]<<", ";
	}
	cout<<endl;
	return 0;
}