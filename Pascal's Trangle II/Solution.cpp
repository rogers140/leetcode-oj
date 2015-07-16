#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        result.push_back(1);
        double numerator = rowIndex;
        double denominator = 1;
        for (int i = 1; i < rowIndex + 1; ++i) {
        	// Pay attention to type casting.
        	// Integer type is too small in some situation
        	int value = numerator * result[i - 1] / denominator;
        	--numerator;
        	++denominator;
        	result.push_back(value);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector<int> result = s->getRow(30);
	for (int i : result) {
		cout<<i<<",";
	}
	cout<<endl;
	return 0;
}