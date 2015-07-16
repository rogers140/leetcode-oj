#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
    	if (triangle.empty()) {
    		return 0;
    	}
        vector<vector<int> > minTotal(triangle);
        for (int i = minTotal.size() - 2; i >= 0; --i) {
        	for (int j = 0; j < minTotal[i].size(); ++j) {
        		minTotal[i][j] += minTotal[i + 1][j] < minTotal[i + 1][j + 1] ? 
        					      minTotal[i + 1][j] : minTotal[i + 1][j + 1];
        	}
        }
        return minTotal[0][0];
    }
};
int main(int argc, char const *argv[])
{
	vector<int> row1, row2, row3, row4;
	row1.push_back(2);
	row2.push_back(3);
	row2.push_back(4);
	row3.push_back(6);
	row3.push_back(5);
	row3.push_back(7);
	row4.push_back(4);
	row4.push_back(1);
	row4.push_back(8);
	row4.push_back(3);

	vector<vector<int> > triangle;
	triangle.push_back(row1);
	triangle.push_back(row2);
	triangle.push_back(row3);
	triangle.push_back(row4);

	Solution *s = new Solution();
	cout<<s->minimumTotal(triangle)<<endl;
	return 0;
}
