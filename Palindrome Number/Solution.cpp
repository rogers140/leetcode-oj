#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        	return false;
        if (x < 10)
        	return true;
        if (x % 10 == 0)
        	return false;
        int reverse = 0;
        while (x > reverse){
        	reverse = reverse * 10 + x % 10;
        	x = x / 10;
        }
        if (x == reverse || x == reverse / 10) {
        	return true;
        }
        else 
        	return false;

    }
};

int main(int argc, char const *argv[]) {
	Solution *s = new Solution();
	cout<<s->isPalindrome(131)<<endl;
	return 0;
}