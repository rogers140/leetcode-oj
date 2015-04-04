#include <stdio.h>
#include <iostream>
using namespace std;
//to merge it backwards and avoid overlapping
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while(i >= 0 && j >= 0) {
        	if(A[i] > B[j]) {
        		A[k] = A[i];
        		--k;
        		--i;
        	}
        	else {
        		A[k] = B[j];
        		--k;
        		--j;
        	}
        }
        while(j >= 0) {
        	A[k] = B[j];
        	--k;
        	--j;
        }
    }
};
int main(int argc, char const *argv[])
{
	int A[] = {3, 5, 7, 10, 20, 21, 34, 0, 0, 0, 0, 0, 0, 0, 0};
	int B[] = {4, 7, 10, 29};
	Solution *s = new Solution();
	int m = 7;
	int n = 4;
	s->merge(A, m, B, n);
	for(int i = 0; i < m + n; ++i) {
		cout<<A[i]<<", ";
	}
	cout<<endl;
	return 0;
}