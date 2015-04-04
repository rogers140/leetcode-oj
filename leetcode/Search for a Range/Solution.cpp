#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int start = -1;
        int end = -1;

        //先找到任意一个，然后向前向后分别二分查找边界
        int pivot = binarySearch(A, 0, n - 1, target);
        //cout<<pivot<<endl;
       	if (pivot != -1) {
       		start = findLeft(A, 0, pivot,target);
       		end = findRight(A, pivot, n - 1, target);
       	}


        vector<int> result(2);
        result[0] = start;
        result[1] = end;
        return result;
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

    int findLeft(int A[], int low, int high, int target) {
    	if (low == high) {
    		return low;
    	}
    	if (low == high - 1) {
    		if (A[low] == target) {
    			return low;
    		}
    		else {
    			return high;
    		}
    	}
    	int mid = (low + high) / 2;
    	if (A[mid] < target) {
    		return findLeft(A, mid, high, target);
    	}
    	else {
    		return findLeft(A, low, mid, target);
    	}
    }

    int findRight(int A[], int low, int high, int target) {
    	if (low == high) {
    		return low;
    	}
    	if (low == high - 1) {
    		if (A[high] == target) {
    			return high;
    		}
    		else {
    			return low;
    		}
    	}
    	int mid = (low + high) / 2;
    	if (A[mid] > target) {
    		return findRight(A, low, mid, target);
    	}
    	else {
    		return findRight(A, mid, high, target);
    	}
    }
};

int main(int argc, char const *argv[]) {
	
	Solution *s = new Solution();
	int array[] = {1,2,3,3,3,3,4,5,9};
	vector<int> result = s->searchRange(array, 9, 3);
	for (int i = 0; i < 2; ++i) {
		cout<<result[i]<<endl;
	}
	return 0;
}