#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int rowNum = matrix.size();
        if(rowNum == 0) {
        	return;
        }
        int colNum = matrix[0].size();
        if(colNum == 0) {
        	return;
        }
        // use first row and column to store the information
        bool hasZeroFirstRow = false;
        bool hasZeroFirstCol = false;
        // test first row
        for(int j = 0; j < colNum; ++j) {
        	if(matrix[0][j] == 0) {
        		hasZeroFirstRow = true;
        		break;
        	}
        }
        // test first column
        for(int i = 0; i < rowNum; ++i) {
        	if(matrix[i][0] == 0) {
        		hasZeroFirstCol = true;
        		break;
        	}
        }
        // find zeroes and store the info in first row and column
        for(int i = 1; i < rowNum; ++i) {
        	for(int j = 1; j < colNum; ++j) {
        		if(matrix[i][j] == 0) {
        			matrix[i][0] = 0;
        			matrix[0][j] = 0;
        		}
        	}
        }
        // set zeroes except the first row and column
        for(int i = 1; i < rowNum; ++i) {
        	for(int j = 1; j < colNum; ++j) {
        		if(matrix[i][0] == 0 || matrix[0][j] == 0) {
        			matrix[i][j] = 0;
        		}
        	}
        }
        // set zeroes for first row and column if needed
        if(hasZeroFirstRow) {
        	for(int j = 0; j < colNum; ++j) {
        		matrix[0][j] = 0;
        	}
        }
        if(hasZeroFirstCol) {
        	for(int i = 0; i < rowNum; ++i) {
        		matrix[i][0] = 0;
        	}
        }

    }
};
int main(int argc, char const *argv[])
{
	
	return 0;
}