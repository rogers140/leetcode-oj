#include <stdio.h>
#include <iostream>
using namespace std;
class Solution {
public:
    bool canJump(int A[], int n) {
    	if(n == 0 || n == 1) {
    		return true;
    	}
    	int largestRange = A[0];
        for(int i = 0; i < n; ++i) {
        	if(i > largestRange) {
        		return false;
        	}
        	else {
        		if(A[i] + i > largestRange) {
        			largestRange = A[i] + i;
        		}
        	}
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	int A1[] = {2, 3, 1, 1, 4};
	int A2[] = {3, 2, 1, 0, 4};
	cout<<s->canJump(A1, 5)<<endl;
	cout<<s->canJump(A2, 5)<<endl;

	return 0;
}