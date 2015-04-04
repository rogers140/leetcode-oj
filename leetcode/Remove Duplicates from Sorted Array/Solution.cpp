#include <stdio.h>
#include <iostream>
using namespace std;
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		int counter = 0;
		/* 
		** Do not push all the list forward.
		** When we find an item that is different from previous
		** one stored in A[counter - 1], we put it into A[counter]
		*/
		for(int i = 0; i < n; ++i) {
			if(counter == 0 || A[i] != A[counter - 1]) {
				A[counter] = A[i];
				++counter;
			}
		}
		return counter;
	}
};

int main(int argc, char const *argv[]) {
	Solution *s = new Solution();
	int array[] = {1, 2, 3, 3, 5, 6, 6, 6, 6};
	int length = s->removeDuplicates(array, 9);
	for(int i = 0; i < length; ++i) {
		cout<<array[i]<<", ";
	}
	cout<<endl;
	return 0;
}
