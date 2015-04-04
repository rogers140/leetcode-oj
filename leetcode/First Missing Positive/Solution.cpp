#include <stdio.h>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
    	//very tricky. Since we only have n numbers, so the first missing
    	//positive must be in [1, n + 1]
    	if (n == 0) return 1;
    	for (int i = 0; i < n; ++i) {
    		//put value (inside [1, n]) into right cell
    		if (A[i] > 0 && A[i] <= n && A[i] != i + 1) {
    			if (A[A[i] - 1] != A[i]) {
    				int temp = A[A[i] - 1];
    				A[A[i] - 1] = A[i];
    				A[i] = temp;
    				--i;
    			}
    		}
    	}
    	for (int i = 0; i < n; ++i) {
    		if (A[i] != i + 1) {
    			return i + 1;
    		}
    	}
    	return n + 1;
    }
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	int test1[] = {1, 2, 0};
	int test2[] = {3, 4, -1, 1};
 	cout<<s->firstMissingPositive(test1, 3)<<endl;
 	cout<<s->firstMissingPositive(test2, 4)<<endl;
	return 0;
}