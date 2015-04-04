#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int lengthA = a.size();
        int lengthB = b.size();
        int carry = 0;
        if(lengthA < lengthB) {
        	int distance = lengthB - lengthA;
        	for(int ptr = lengthA - 1; ptr >= 0; --ptr) {
        		int numA = a[ptr] - '0';
        		int numB = b[ptr + distance] - '0';
        		b[ptr + distance] = (numA + numB + carry) % 2 + '0';
        		carry = (numA + numB + carry) / 2;
        	}
        	if(carry != 1) {
        		return b;
        	}
        	else {
        		for(int i = distance - 1; i >= 0; --i) {
        			int numB = b[i] - '0';
        			b[i] = (numB + carry) % 2 + '0';
        			carry = (numB + carry) / 2;
        		}
        		if(carry == 1) {
        			string result = "1";
        			result.append(b);
        			return result;
        		}
        		else {
        			return b;
        		}
        	}
        }
        else {// lengthA >= lengthB
        	int distance = lengthA - lengthB;
        	for(int ptr = lengthB - 1; ptr >= 0; --ptr) {
        		int numA = a[ptr + distance] - '0';
        		int numB = b[ptr] - '0';
        		a[ptr + distance] = (numA + numB + carry) % 2 + '0';
        		carry = (numA + numB + carry) / 2;
        	}
        	if(carry != 1) {
        		return a;
        	}
        	else {
        		for(int i = distance - 1; i >= 0; --i) {
        			int numA = a[i] - '0';
        			a[i] = (numA + carry) % 2 + '0';
        			carry = (numA + carry) / 2;
        		}
        		if(carry == 1) {
        			string result = "1";
        			result.append(a);
        			return result;
        		}
        		else {
        			return a;
        		}
        	}
        }
    }
};
int main(int argc, char const *argv[])
{
	string a = "101111";
	string b = "10";
	Solution *s = new Solution();
	string result = s->addBinary(a, b);
	cout<<result<<endl;
	return 0;
}