#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < 9; ++i) {
            if (!checkRows(board, i))
                return false;
            if (!checkColumns(board, i))
                return false;
        }
        return checkBlocks(board);
    }

    bool checkRows(vector<vector<char> > &board, int row_num) {
        vector<char> row(board[row_num]);
        return checkNumbers(row);
    }

    bool checkColumns(vector<vector<char> > &board, int column_num) {
        vector<char> column(9, '.');
        for (int i = 0; i < 9; ++i) {
            column[i] = board[i][column_num];
        }
        return checkNumbers(column);
    }

    bool checkBlocks(vector<vector<char> > &board) {
        vector<char> block;
        vector<vector<char> > block_array(9, block);
        for (int i = 0; i < 81; ++i) {
            int row = i / 9;
            int column = i % 9;
            int block_index = (row / 3) * 3 + column / 3;
            block_array[block_index].push_back(board[row][column]);
        }
        for (int i = 0; i < 9; ++i) {
            if (!checkNumbers(block_array[i]))
                return false;
        }
        return true;
    }
    bool checkNumbers(vector<char> &num_set) {
        if (num_set.size() != 9) {
            return false;
        }
        int temp[9] = {0}; //set all to not exist
        for (int i = 0; i < 9; ++i) {
            if (num_set[i] == '.') continue;
            int index = num_set[i] - 49;
            if ((index < 9) && (index >= 0) && (temp[index] == 0)) {
                temp[index] = 1;
            }
            else {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
	
	return 0;
}