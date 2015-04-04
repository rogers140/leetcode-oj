#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        string result(n, '0');
        vector<int> array(n, 0);
        for(int i = 0; i < n; ++i) {
        	array[i] = i + 1;
        }
        vector<int> cacheOfN;
        int multiple = 1;
        cacheOfN.push_back(multiple);
        for(int i = 1; i < n; ++i) {
        	multiple = multiple * i;
        	//cout<<multiple<<endl;
        	cacheOfN.push_back(multiple);
        }
        if(k < 1 || k > n * cacheOfN[n - 1]) {
        	return result;
        }
        int index = 0;
        --k;
        while (index < n) {
        	int temp  = k / cacheOfN[n - index - 1];
        	result[index] += array[temp];
        	array.erase(array.begin() + temp, array.begin() + temp + 1);
        	k = k % cacheOfN[n - index - 1];
        	++index;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	cout<<s->getPermutation(4, 5)<<endl;
	return 0;
}