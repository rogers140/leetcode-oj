#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
    int sqrt(int x) {
    	if(x<=0)
        	return x;
    	double st=0;
    	double en=x;
    	double mid=(st+en)/2;

    	while(fabs(st-en)>=0.000001)
    	{
        	if(mid*mid<x){
            	st=mid;
        	}
        	else{
            	en=mid;
        	}
        	mid=(st+en)/2.0;
    	}
    	return static_cast<int> (en);
	}
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	cout<<s->sqrt(2147395599)<<endl;
	return 0;
}