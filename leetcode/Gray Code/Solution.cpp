#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
//http://en.wikipedia.org/wiki/Gray_code
//and you will know how to generate it
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1, 0);
        for(int i = 0; i < n; ++i) {
        	int length = result.size();
        	for(int j = length - 1; j >= 0; --j) {
        		int num = result[j];
        		num += (1<<i);
        		result.push_back(num);
        	}
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	vector<int> result = s->grayCode(2);
	for(int i = 0; i < result.size(); ++i) {
		cout<<result[i]<<", ";
	}
	cout<<endl;
	return 0;
}