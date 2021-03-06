#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	string multiply(string num1, string num2) {
		string result = "0";
		if (num1.empty() || num2.empty() || num1 == "0" || num2 == "0") {
			return result;
		}
		int length1 = num1.length();
		int length2 = num2.length();
		int position = 0;
		for (int i = length2 - 1; i >= 0; --i) {
			int multiplier2 = num2[i] - 48;
			int carry = 0;
			string temp_str = "";
			for (int j = length1 - 1; j >= 0; --j) {
				int multiplier1 = num1[j] - 48;
				int temp = 0;
				temp = temp + multiplier1 * multiplier2 + carry;
				carry = temp / 10;
				char temp_char = temp % 10 + 48;
				temp_str.append(1, temp_char);
			}
			if (carry > 0) {
				char temp_char = carry + 48;
				temp_str.append(1, temp_char);
			}
			string current(temp_str.rbegin(), temp_str.rend());
			current.append(position, '0');
			result = add(result, current);
			++position;
		}
		return result;
	}
	string add(string num1, string num2) {
		string result = "";
		int carry = 0;
		int length1 = num1.length();
		int length2 = num2.length();
		if (length1 > length2) {
			for (int i = length1 - 1; i >= 0; --i) {
				int temp = num1[i] - 48;
				if ( i - length1 + length2 >= 0) {
					temp +=num2[i - length1 + length2] - 48;
				}
				temp += carry;
				if(temp >= 10) {
					carry = 1;
					temp = temp - 10;
				} 
				else {
					carry = 0;
				}
				char temp_char = temp + 48;
				result.append(1, temp_char);
			}
		}
		else {
			for (int i = length2 - 1; i >= 0; --i) {
				int temp = num2[i] - 48;
				if (i - length2 + length1 >= 0) {
					temp += num1[i - length2 + length1] - 48;
				}
				temp += carry;
				if(temp >= 10) {
					carry = 1;
					temp = temp - 10;
				} 
				else {
					carry = 0;
				}
				char temp_char = temp + 48;
				result.append(1, temp_char);
			}
		}
		if (carry == 1) {
			result.append("1");
		}
		string ret(result.rbegin(), result.rend());
		return ret;
	}
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	cout<<s->multiply("12321", "0")<<endl;
	return 0;
}