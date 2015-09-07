#include <iostream>
#include <limits>
using namespace std;
/*
ret = a0 + a1*2 + a2*2^2 + ...... + a29*2^29 + a30*2^30 + a31*2^31; ai = 0 or 1, i = 0......31

the dividend B and divisor A is non-negative, then

A(a0 + a1*2 + a2*2^2 + ...... + a29*2^29 + a30*2^30 + a31*2^31) = B; Eq1

(1) when Eq1 divided by 2^31, we can get A*a31 = B>>31; then a31 = (B>>31)/A;

if (B>>31) > A, then a31 = 1; else a31 = 0;

(2) when Eq1 divided by 2^30, we can get A*a30 + A*a30*2 = B>>30; then a30 = ((B>>30) - a30*A*2)/A; and (B>>30) - a31*A*2 can be rewritten by (B-a31*A<<31)>>30, so we make B' = B-a31*A<<31, the formula simplified to a30 = (B'>>30)/A

if (B'>>31) > A, then a30 = 1; else a30 = 0;

(3) in the same reason, we can get a29 = ((B-a31*A<<31-a30*A<<30)>>29)/A, we make B'' = B' - a30*A<<30, the formula simplified to a29 = (B''>>29)/A;

do the same bit operation 32 times, we can get a31 ..... a0, so we get the ret finally.

the C solution with constant time complexity
*/
class Solution {
public:
	int divide(int dividend, int divisor) {
    //special cases
    if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
      return INT_MAX;

    // transform to unsigned int
    bool sign = (dividend > 0)^(divisor > 0);
    unsigned int A = (divisor < 0) ? -divisor : divisor;
    unsigned int B = (dividend < 0) ? -dividend : dividend;
    int ret = 0;

    // shift 32 times
    for (int i = 31; i >= 0; i--) {
      if ((B>>i) >= A) {
        ret = (ret<<1)|0x01;
        B -= (A<<i);   // update B
      }
      else
        ret = ret<<1;
    }

    if(sign)
      ret = -ret;
    return ret;
  }
};

int main(int argc, char const *argv[])
{
	
	return 0;
}