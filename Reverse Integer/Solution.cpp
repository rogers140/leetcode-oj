#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        if (x < 0) 
            neg = true, x = -x;
        unsigned int ret = 0;
        while (x / 10) {
            ret = ret * 10 + x % 10;
            x = x / 10;
        }
        ret = ret * 10 + x;
        if (ret > 0x7fffffff) return 0; //overflow check.
        if (neg) return -(int)ret;
        return (int)ret;
    }
};

int main(int argc, char const *argv[]){
	int test1 = 1234567;
	int test2 = -1234;
	int test3 = 100;
	int test4 = 1000000003;

	Solution *s = new Solution();
	cout<<"reverse of test1 : "<<s->reverse(test1)<<endl;
	cout<<"reverse of test2 : "<<s->reverse(test2)<<endl;
	cout<<"reverse of test3 : "<<s->reverse(test3)<<endl;
	cout<<"reverse of test4 : "<<s->reverse(test4)<<endl;
	return 0;
}