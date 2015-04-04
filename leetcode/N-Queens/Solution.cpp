#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
class Solution {
public:	
	vector<vector<string> > solveNQueens(int n) {
		int initial = -10000;
		vector<int> record(n, initial); // record the place of queen for each row, -1 means not available
		vector<vector<string> > result;
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
				addSolution(result, record); //found one solution, but we should keep searching
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
	void addSolution(vector<vector<string> > &result, vector<int> &record) {
		vector<string> currentSolution;
		for(int i = 0; i < record.size(); ++i) {
			string temp(record.size(), '.');
			temp[record[i]] = 'Q';
			currentSolution.push_back(temp);
		}
		result.push_back(currentSolution);
	}
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector<vector<string> > result = s->solveNQueens(4);
	for(int i = 0; i < result.size(); ++i) {
		for(int j = 0; j < result[i].size(); ++j) {
			cout<<result[i][j]<<","<<endl;
		}
		cout<<endl;
	}
	return 0;
}