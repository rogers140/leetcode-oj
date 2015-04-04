#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
	int atoi(const char *str) {
		int length = strlen(str);
		int sign = 1;
		int start = 0;
		for (int i = 0; i < length; i++) {
			if (str[i] == ' ' || str[i] == 0x9) {
				start++;
			}
			else {
				break;
			}
		}
		if (str[start] == '-') {
			sign  = -1;
			start++;
		}
		else if (str[start] == '+') {
			sign  =  1;
			start ++;
		}
		unsigned int result = 0;
		for (int i = start; i < length; i++) {
			if (isdigit(str[i])) {
				int digit = str[i] - '0';
				if (INT_MAX / 10 >= result)
                	result *= 10;
            	else
                	return sign == -1 ? INT_MIN : INT_MAX;
                 
            	if (INT_MAX - digit >= result)
                	result += digit;
            	else
                	return sign == -1 ? INT_MIN : INT_MAX;
			}
			else { //illegal input
				break;
			}
		}
		return sign*((int)result);
	

	}
};

int main(int argc, char const *argv[]) {
	Solution *s = new Solution();
	const char *test1 = "1";
	const char *test2 = "123 456";
	const char *test3 = "    10522545459";
	const char *test4 = "  -0012a42";
	const char *test5 = "    +004500";
	const char *test6 = "30000000000000000";
	cout<<"test1 : "<<s->atoi(test1)<<endl;
	cout<<"test2 : "<<s->atoi(test2)<<endl;
	cout<<"test3 : "<<s->atoi(test3)<<endl;
	cout<<"test4 : "<<s->atoi(test4)<<endl;
	cout<<"test5 : "<<s->atoi(test5)<<endl;
	cout<<"test6 : "<<s->atoi(test6)<<endl;
	return 0;
}