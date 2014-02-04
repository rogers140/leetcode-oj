#include <stdio.h>
#include <iostream>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
    	int total = m + n;
		if (total & 0x1)//total number is odd
			return findKth(A, m, B, n, total / 2 + 1);
		else
			return (findKth(A, m, B, n, total / 2) + findKth(A, m, B, n, total / 2 + 1)) / 2;
    }
    double findKth(int a[], int m, int b[], int n, int k) {
		if (m > n)
			return findKth(b, n, a, m, k);
		if (m == 0)
			return b[k - 1];
		if (k == 1)
			return min(a[0], b[0]);
		//everytime, remove k/2 elements
		int pa = min(k/2, m), pb = k - pa;
		if (a[pa - 1] < b[pb - 1])
			return findKth(a + pa, m - pa, b, n, k - pa);
		else if (a[pa - 1] > b[pb - 1])
			return findKth(a, m, b + pb, n - pb, k - pb);
		else
			return a[pa - 1];
	}
};

int main(int argc, char const *argv[]) {
	int a[] = {2, 6, 9, 10, 13, 22, 45, 60, 66};
	int b[] = {7, 9, 12, 25, 27, 36, 55};
	cout<<(new Solution())->findMedianSortedArrays(a, 9, b, 7)<<endl;
	return 0;
}