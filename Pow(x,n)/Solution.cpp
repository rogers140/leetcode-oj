#include <stdio.h>
#include <iostream>
using namespace std;
class Solution {
public:
	double pow(double x, int n) {
		if(n < 0) {
			if(n == -2147483648) {
				return 1 / (x * pow(x, -(n + 1)));
			}
			double result = 1 / pow(x, -n);
			return result;
		} 
		else {
			if (n == 1) {
				return x;
			}
			else if(n == 2) {
				return x * x;
			}
			else if (n == 0) {
				return 1;
			}
			else if(n % 2 != 0) {
				return x * pow(x, n - 1);
			}
			else {// n is even
				double temp = pow(x, n / 2);
				return temp * temp;
			}
		}
		
	}
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	cout<<s->pow(1.00000, -2147483648)<<endl;
	cout<<s->pow(9, 100)<<endl;
	return 0;
}