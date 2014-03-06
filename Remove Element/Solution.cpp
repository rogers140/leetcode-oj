#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		int front = 0;
		int back = n - 1;
		int length = n;
		while(front <= back) {
			//put all the elem into the back of the array
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
	}
};

int main(int argc, char const *argv[]) {
	Solution *s = new Solution();
	int array[] = {3,4};
	int length = s->removeElement(array, 2, 4);
	for(int i = 0; i < length; ++i) {
		cout<<array[i]<<",";
	}
	cout<<endl;
	return 0;
}