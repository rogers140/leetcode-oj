#include <stdio.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n == 0) {
        	return 0;
        }
        int maxium = A[0];
        //O(n*n)
        // for(int i = 0; i < n; ++i) {
        // 	int localMaxium = A[i];
        // 	int currentSum = 0;
        // 	for(int j = i; j < n; ++j) {
        // 		currentSum += A[j];
        // 		if(currentSum > localMaxium) {
        // 			localMaxium = currentSum;
        // 		}
        // 	}
        // 	if(localMaxium > maxium) {
        // 		maxium = localMaxium;
        // 	}
        // }

        //O(n)
        int sum = 0;
        for(int i = 0; i < n; ++i) {
        	if(sum >= 0) {
        		sum += A[i];
        	}
        	else {
        		sum = A[i];
        	}
        	if(sum > maxium) {
        		maxium = sum;
        	}
        }
        return maxium;
    }
};
int main(int argc, char const *argv[])
{
	int A[9]={-2, 1, -3, 4, -1, 2, 1, -5, 4};
	Solution *s = new Solution();
	cout<<s->maxSubArray(A, 9)<<endl;
	return 0;
}