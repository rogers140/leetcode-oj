#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) 
    {
        reverse(matrix.begin(), matrix.end());
        for (unsigned i = 0; i < matrix.size(); ++i)
            for (unsigned j = i+1; j < matrix[i].size(); ++j)
                swap (matrix[i][j], matrix[j][i]);
    }
};
int main(int argc, char const *argv[])
{
	vector<vector<int> > matrix;
	vector<int> rowOne;
	vector<int> rowTwo;
	vector<int> rowThree;

	rowOne.push_back(1);
	rowOne.push_back(2);
	rowOne.push_back(3);

	rowTwo.push_back(4);
	rowTwo.push_back(5);
	rowTwo.push_back(6);

	rowThree.push_back(7);
	rowThree.push_back(8);
	rowThree.push_back(9);

	matrix.push_back(rowOne);
	matrix.push_back(rowTwo);
	matrix.push_back(rowThree);

	Solution *s = new Solution();
	s->rotate(matrix);
	for(int i = 0; i < matrix.size(); ++i) {
		for(int j = 0; j < matrix[i].size(); ++j) {
			cout<<matrix[i][j]<<",";
		}
		cout<<endl;
	}
	return 0;
}