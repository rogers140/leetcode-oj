#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int row = matrix.size();
        if(row == 0) {
        	return 0;
        }
        int col = matrix[0].size();
        if(col == 0) {
        	return 0;
        }
        for(int i = 0; i < row; ++i) {//reset the matrix[i][j] with the number of continous 1's from its right side
        	int current = 0;
        	for(int j = col - 1; j >= 0; --j) {
        		if(matrix[i][j] == '1') {
        			++current;
        			matrix[i][j] = current;
        		}
        		else {
        			current = 0;
        			matrix[i][j] = 0;
        		}
        	}
        }
        int maxArea = 0;
        for(int i = 0; i < row; ++i) {
        	for(int j = 0; j < col; ++j) {
        		int currentArea = matrix[i][j];
        		if(currentArea == 0) {
        			continue;
        		}
        		else {
        			int k = 1;
        			while(i + k < row) {
        				if(matrix[i + k][j] >= matrix[i][j]) {
        					currentArea += matrix[i][j];
        				}
        				else {
        					break;
        				}
        				++k;
        			}
        			k = 1;
        			while(i - k >= 0) {
        				if(matrix[i - k][j] >= matrix[i][j]) {
        					currentArea += matrix[i][j];
        				}
        				else {
        					break;
        				}
        				++k;
        			}
        			if(currentArea > maxArea) {
        				maxArea = currentArea;
        			}
        		}
        	}
        }
        return maxArea;
    }
};
int main(int argc, char const *argv[])
{
	char row1[] = {'0', '1', '1', '0', '1', '0'};
	char row2[] = {'1', '0', '1', '1', '1', '1'};
	char row3[] = {'0', '1', '1', '1', '0', '0'};
	char row4[] = {'0', '0', '0', '0', '0', '0',};
	vector<char> rowOne(row1, row1 + 6);
	vector<char> rowTwo(row2, row1 + 6);
	vector<char> rowThree(row3, row1 + 6);
	vector<char> rowFour(row4, row1 + 6);
	vector<vector<char> > matrix;
	matrix.push_back(rowOne);
	matrix.push_back(rowTwo);
	matrix.push_back(rowThree);
	matrix.push_back(rowFour);

	Solution *s = new Solution();
	cout<<s->maximalRectangle(matrix)<<endl;
	return 0;
}