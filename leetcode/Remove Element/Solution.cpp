#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		//the first is a little tricky.
		int count = 0;
		for(int i = 0; i < n; ++i) {
			if(A[i] == elem) {
				++count;
			}
			else if(count > 0) {
				A[i - count] = A[i];
			}
		}
		return n - count;
		/* 
		// The second method is much easier to understand.
		// Put all elements that should be delete to the end of the array.
		int front = 0;
		int back = n - 1;
		int length = n;
		while(front <= back) {
			if(A[front] == elem) {
				--length;
				while((A[back] == elem) && (front < back)) { 
					--back;
					--length;
				}
				if(front < back) {					
					A[front] = A[back];
					A[back] = elem;
					++front;
					--back;
				}
				else if(front == back) {
					break;
				}
			}
			else {
				++front;
			}
		}
		return length;
		*/

	}
};

int main(int argc, char const *argv[]) {
	Solution *s = new Solution();
	int array[] = {3,4,5,6,4,4,6};
	int length = s->removeElement(array, 7, 4);
	for(int i = 0; i < length; ++i) {
		cout<<array[i]<<",";
	}
	cout<<endl;
	return 0;
}