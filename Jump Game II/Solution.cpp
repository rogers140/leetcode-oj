#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        int last = 0; //maxium distance that can be reached by numOfSteps
        int current = 0; //maxium distance that can be reached by numOfSteps + 1 
        int numOfSteps = 0;
        
        for(int i = 0; i < n; ++i) {
        	if(i > last) {
        		last = current;
        		++numOfSteps;
        	}
        	current = max(current, i + A[i]);
        }
        return numOfSteps;
    }
    int jumpPlus(int A[], int index, int n) {//take too much time
    	int largest_step = A[index];
    	//cout<<largest_step<<endl;
    	if(n - 1 - index <= largest_step) {
    		return 1;
    	}
    	int minum_jump = n - largest_step;
    	for(int i = 1; i <= largest_step; ++i) {
    		if(A[index + i] == 0) {//trapped in the cell
    			continue;
    		}
    		int current_jump = 1 + jumpPlus(A, index + i, n);
    		if(current_jump < minum_jump) {
    			minum_jump = current_jump;
    		}
    	}
    	return minum_jump;
    }
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	int A[] = {5,6,4,4,6,9,4,4,7,4, 4,8,2,6,8,1,5,9,6,5, 2,7,9,7,9,6,9,4,1,6, 8,8,4,4,2,0,3,8,5};
	cout<<s->jump(A, 39)<<endl;
	return 0;
}