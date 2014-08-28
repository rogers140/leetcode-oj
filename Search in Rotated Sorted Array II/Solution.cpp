#include <stdio.h>
#include <iostream>
using namespace std;
class Solution {
//needs to be read more
public:
    bool search(int A[], int n, int target) {
        int l = 0, r = n - 1;
    	while (l <= r) {
        	int m = l + (r - l)/2;
        	if (A[m] == target) return true; //return m in Search in Rotated Array I
        	if (A[l] < A[m]) { //left half is sorted
            	if (A[l] <= target && target < A[m])
                	r = m - 1;
            	else
                	l = m + 1;
        	} 
        	else if (A[l] > A[m]) { //right half is sorted
            	if (A[m] < target && target <= A[r])
                	l = m + 1;
            	else
                	r = m - 1;
        	} 
        	else l++;
    }
    return false;
    }
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	int A[] = {1, 1, 5, 1, 1, 1, 1};
	cout<<s->search(A, 7, 5)<<endl;
	return 0;
}