#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
class Solution {
public:	
	int totalNQueens(int n) {
		int initial = -10000;
		vector<int> record(n, initial); // record the place of queen for each row, -1 means not available
		int result = 0;
		int row = 0;
		int column = 0;
		while(row < n) {
			while(column < n) {
				if(isValid(record, row, column)) {
					record[row] = column;
					column = 0;
					break;
				}
				else {
					++column;
				}
			}
			if(record[row] == initial) { 
				if(row == 0) {
					break; //trace back to the first row means we found all solution
				}
				else {//not found, step back;
					--row;
					column = record[row] + 1;
					record[row] = initial;
					continue;
				}
			}
			if(row == n - 1) {
				++result;
				column = record[row] + 1;
				record[row] = initial;
				continue;
			}
			++ row;
		}
		return result;
	}
	bool isValid(vector<int> &record, int row, int column) {
		for(int i = 0; i < record.size(); ++i) {
			if(record[i] == column || abs(i - row) == abs(record[i] - column)) {
				return false;
			}
		}
		return true;
	}
	void clearBoard(vector<int> &record) {
		int initial = -10000;
		for(int i = 0; i < record.size(); ++i) {
			record[i] = initial;
		}
	}
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	int result = s->totalNQueens(4);
	cout<<result<<endl;
	return 0;
}