#include <stdio.h>
#include <iostream>
using namespace std;
/* 
rules of roman numbers are referred to http://projecteuler.net/about=roman_numerals
I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000

Only I, X, and C can be used as the leading numeral in part of a subtractive pair.
I can only be placed before V and X.
X can only be placed before L and C.
C can only be placed before D and M.
*/
class Solution {
public:
    string intToRoman(int num) {
        string result;
        // M
        int num_of_m = num / 1000;
        for (int i = 0; i < num_of_m; ++i) {
        	result += "M";
        }
        if ((num + 100) / 1000 == num_of_m + 1) {
        	result += "CM";
        	++num_of_m;
        	num = num - (num_of_m * 1000 - 100);
        }
        else {
        	num = num - num_of_m * 1000;
        }
        //D
        int num_of_d = num / 500;
        for (int i = 0; i < num_of_d; ++i) {
        	result += "D";
        }
        if ((num + 100) / 500 == num_of_d + 1) {
        	result += "CD";
        	++num_of_d;
        	num = num - (num_of_d * 500 - 100);
        }
        else {
        	num = num - num_of_d * 500;
        }
        //C
        int num_of_c = num / 100;
        for (int i = 0; i < num_of_c; ++i) {
        	result += "C";
        }
        if ((num + 10) / 100 == num_of_c +1) {
        	result += "XC";
        	++num_of_c;
        	num = num - (num_of_c * 100 - 10);
        }
        else {
        	num = num - num_of_c * 100;
        }
        //L
        int num_of_l = num / 50;
        for (int i = 0; i < num_of_l; ++i) {
        	result += "L";
        }
        if ((num + 10) / 50 == num_of_l +1) {
        	result += "XL";
        	++num_of_l;
        	num = num - (num_of_l * 50 - 10);
        }
        else {
        	num = num - num_of_l * 50;
        }
        //X
        int num_of_x = num / 10;
        for (int i = 0; i < num_of_x; ++i) {
        	result += "X";
        }
        if ((num + 1) / 10 == num_of_x +1) {
        	result += "IX";
        	++num_of_x;
        	num = num - (num_of_x * 10 - 1);
        }
        else {
        	num = num - num_of_x * 10;
        }
        //V
        int num_of_v = num / 5;
        for (int i = 0; i < num_of_v; ++i) {
        	result += "V";
        }
        if ((num + 1) / 5 == num_of_v+1) {
        	result += "IV";
        	++num_of_v;
        	num = num - (num_of_v * 5 - 1);
        }
        else {
        	num = num - num_of_v * 5;
        }
        //I
        int num_of_i = num;
        for (int i = 0; i < num_of_i; ++i) {
        	result += "I";
        }


        return result;
    }
};

int main(int argc, char const *argv[]) {
	Solution *s = new Solution();
	cout<<(s->intToRoman(3999))<<endl;
	return 0;
}