#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
    //n is the length of array A.
    	if (n == 1) {
    		if (A[0] == target) {
    			return 0;
    		}
    		else {
    			return -1;
    		}
    	}
    	int pivot = pivotSearch(A, 0, n - 1);
    	if (pivot == -1) {
    		return binarySearch(A, 0, n - 1, target);
    	}
    	//cout<<"pivot: "<<pivot<<endl;
    	if (target >= A[0]) {
    		return binarySearch(A, 0, pivot, target);
    	}
    	else {
    		return binarySearch(A, pivot + 1, n - 1, target);
    	}
        
    }

    int pivotSearch(int A[], int start, int end) {
    	if (start > end) {
    		return -1;
    	}
    	int mid = (start + end) / 2;
    	if (end - start == 1) {//only two element
    		if (A[start] > A[end]) 
    			return start;
    		else 
    			return -1;
    	}
    	if (A[mid] > A[mid + 1]) 
    		return mid;
    	if (A[mid - 1] > A[mid]) 
    		return mid - 1;
    	if (A[mid] > A[start]) 
    		return pivotSearch(A, mid + 1, end);
    	else
    		return pivotSearch(A, start, mid - 1);
    }

    int binarySearch(int A[], int start, int end, int target) {
    	if (start > end) {
    		return -1;
    	}
    	int mid = (start + end) / 2;
    	if (A[mid] == target) {
    		return mid;
    	}
    	if (A[mid] < target) {
    		return binarySearch(A, mid + 1, end, target);
    	}
    	else {
    		return binarySearch(A, start, mid - 1, target);
    	}
    }
};

int main(int argc, char const *argv[]) {
	
	Solution *s = new Solution();
	int array[] = {3,4,5,6,1,2};
	cout<<s->search(array, 6, 2)<<endl;

	return 0;
}