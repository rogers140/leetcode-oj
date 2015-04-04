#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
/**
 * Solution:
 * Only difference is now we allow two duplicates. So we scan through the 
 * array and if we find the 3rd duplicate we just skip them.
 * We know it's 3rd duplicate by comparing the itor with second last elements in
 * final array (if A[itor] == A[len-2], then A[itor]==A[len-2]==A[len-1])
 */
class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	if(n <= 2) {
    		return n;
    	}
        int length = 2;
        for(int i = 2; i < n; ++i) {
        	if(A[i] != A[length - 2]) {
        		A[length] = A[i];
        		++length;
        	}
        }
        return length;
    }
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	int A[] = {1, 1, 1, 2, 2, 3};
	cout<<s->removeDuplicates(A, 6)<<endl;
	return 0;
}