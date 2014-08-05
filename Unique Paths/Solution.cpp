#include <stdio.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
    	--m; 
        --n; //robot itself takes one block
        double numerator = 1;
        double denominator = 1;
        int less = (m < n) ? m : n;
        //just find how many ways to pick (m-1) steps to go down from (m + n - 2) steps.
        for(int i = m + n; i >= m + n - less + 1; --i) {
        	numerator = numerator * i;
        }
        for(int i = 1; i <= less; ++i) {
        	denominator = denominator * i;
        }

        return (int)(numerator / denominator);
    }
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	cout<<s->uniquePaths(1, 2)<<endl;
	return 0;
}