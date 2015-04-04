#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        searchSolution(board);
    }
    bool searchSolution(vector<vector<char> > &board) {
    	//count the num of empty cell
    	int cell_to_be_filled = 0;
    	int last_row = 0;
    	int last_column = 0;
    	for (int row = 0; row < 9; ++row) {
        	for (int column = 0; column < 9; ++column) {
        		if (board[row][column] == '.') {
        			++cell_to_be_filled;
        			last_row = row;
        			last_column = column;
        		}
        	}
        }
        //judge when to stop recurring
        if (cell_to_be_filled == 1) {
        	for (int value = 1; value <= 9; ++value) {
        		if (checkRow(board, last_row, value) 
        					&& checkColumn(board, last_column, value) 
        					&& checkBlock(board, last_row, last_column, value)) {
        			board[last_row][last_column] = value + 48; 
        			return true;
        		}
        	}
        	return false;
        }
        //not the last one
    	for (int row = 0; row < 9; ++row) {
        	for (int column = 0; column < 9; ++column) {
        		if (board[row][column] != '.') 
        			continue;
        		else {
        			bool found = false;
        			for (int value = 1; value <= 9; ++value) {     				
        				if (checkRow(board, row, value) 
        							&& checkColumn(board, column, value) 
        							&& checkBlock(board, row, column, value)) {
        					board[row][column] = value + 48;
        					if (searchSolution(board)) {
        						found = true;
        						break;
        					}
        				}
        			}
        			if (!found) {//set its value to not no input for other recurring
        				board[row][column] = '.';
        			}
        			return found;
        		}
        	}
        }
    }
    
    bool checkRow(vector<vector<char> > &board, int row_num, int value) {
        vector<char> row(board[row_num]);
        return checkNumbers(row, value);
    }

    bool checkColumn(vector<vector<char> > &board, int column_num, int value) {
        vector<char> column(9, '.');
        for (int i = 0; i < 9; ++i) {
            column[i] = board[i][column_num];
        }
        return checkNumbers(column, value);
    }

    bool checkBlock(vector<vector<char> > &board, int row, int column, int value) {
        int block_index = (row / 3) * 3 + column / 3;
        vector<char> block;
        for (int i = 0; i < 9; ++i) {
        	for (int j = 0; j < 9; ++j) {
        		if(block_index == ((i / 3) * 3 + j / 3)) {
        			block.push_back(board[i][j]);
        		}
        	}
        }
        return checkNumbers(block, value);
    }
    bool checkNumbers(vector<char> &num_set, int value) {
        if (num_set.size() != 9) {
            return false;
        }
        for (int i = 0; i < 9; ++i) {
            if (num_set[i] == '.') continue;
            int index = num_set[i] - 48;
            if (index == value) {//duplicate
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
	
	return 0;
}