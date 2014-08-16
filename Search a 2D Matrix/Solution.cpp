#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int rowNum = matrix.size();
        if(rowNum == 0) {
        	return false;
        }
        int colNum = matrix[0].size();
        if(colNum == 0) {
        	return false;
        }
        //narrow to one row
        int rowIndex = getRowIndex(matrix, target, 0, rowNum - 1);
        if(rowIndex == -1) {
        	return false;
        }
        int colIndex = getColIndex(matrix, target, rowIndex, 0, colNum - 1);
        if(colIndex == -1){
        	return false;
        }
        
        return true;

    }
    int getRowIndex(vector<vector<int> > &matrix, int target, int start, int end) {
    	if(start == end) {
        	if(matrix[start].front() > target || matrix[start].back() < target) {
        		return -1;
        	}
        	else {
        		return start;
        	}
        }
        if(start + 1 == end) {
        	if(matrix[end].front() > target) {
        		return start;
        	}
        	else {
        		return end;
        	}
        }
        int middle = (start + end) / 2;
        if(matrix[middle][0] <= target) {
        	start = middle;
        	return getRowIndex(matrix, target, start, end);
        }
        else {
        	end = middle - 1;
        	return getRowIndex(matrix, target, start, end);
        }
        return -1;
    }
    int getColIndex(vector<vector<int> > &matrix, int target, int rowIndex, int start, int end) {
    	if(start == end) {
    		if(matrix[rowIndex][start] != target) {
    			return -1;
    		}
    		else {
    			return start;
    		}
    	}
    	if(start + 1 == end) {

    		if(matrix[rowIndex][start] == target) {
    			return start;
    		}
    		if(matrix[rowIndex][end] == target) {
    			return end;
    		}
    		return -1;
    	}
    	int middle = (start + end) / 2;
    	if(matrix[rowIndex][middle] < target) {
    		start = middle + 1;
    		return getColIndex(matrix, target, rowIndex, start, end);
    	}
    	else if(matrix[rowIndex][middle] > target) {
    		end = middle - 1;
    		return getColIndex(matrix, target, rowIndex, start, end);
    	}
    	else {
    		return middle;
    	}
    	return -1;
    }

};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector<int> row1;
	vector<int> row2;
	vector<int> row3;

	row1.push_back(1);
	row1.push_back(3);
	row1.push_back(5);
	// row1.push_back(7);

	row2.push_back(10);
	row2.push_back(11);
	row2.push_back(16);
	row2.push_back(20);

	row3.push_back(23);
	row3.push_back(30);
	row3.push_back(34);
	row3.push_back(50);

	vector<vector<int> > matrix;
	matrix.push_back(row1);
	// matrix.push_back(row2);
	// matrix.push_back(row3);
	cout<<s->searchMatrix(matrix, 3)<<endl;
	return 0;
}