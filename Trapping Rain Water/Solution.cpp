#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
	int trap(int A[], int n) {
		if(n == 0) return 0;
        int l = 0, r = n-1,block = 0,all = 0,curlevel = 0;
        while(l <= r) {
            if(min(A[l],A[r]) > curlevel) 
            {
                all += (min(A[l],A[r]) - curlevel) * ( r - l + 1);
                curlevel = min(A[l],A[r]);
            }
            if(A[l] < A[r]) 
                block += A[l++];
            else 
                block += A[r--];
        }
        return all-block;//delete all blocks

	}
};

int main(int argc, char const *argv[])
{
	
	return 0;
}