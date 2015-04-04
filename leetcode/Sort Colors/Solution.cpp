#include <stdio.h>
#include <iostream>
using namespace std;
class Solution {
public:
    void sortColors(int A[], int n) {
    	int endOfRed = -1;
    	int endOfWhite = -1;
    	int endOfBlue = -1;
    	for(int i = 0; i < n; ++i) {
    		switch(A[i]) {
    			case 0:
    				++endOfRed;
    				++endOfWhite;
    				++endOfBlue;
    				//set value from 2 to 0, in case of position shift
    				A[endOfBlue] = 2;
    				A[endOfWhite] = 1;
    				A[endOfRed] = 0;
    				break;
    			case 1:
    				++endOfWhite;
    				++endOfBlue;
    				A[endOfBlue] = 2;
    				A[endOfWhite] = 1;
    				break;
    			case 2:
    				++endOfBlue;
    				A[endOfBlue] = 2;
    				break;
    			default:
    				break;
    		}
    	}
    }
};
int main(int argc, char const *argv[])
{
	int A[] = {1, 0, 2, 2, 1, 1, 2, 0, 1, 0, 2};
	int n = 11;
	Solution *s = new Solution();
	s->sortColors(A, n);
	for(int i = 0; i < n; ++i) {
		cout<<A[i]<<",";
	}
	cout<<endl;
	return 0;
}
