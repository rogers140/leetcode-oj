#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int length = digits.size();
        vector<int> temp(digits);
        if(length == 0) {
        	temp.push_back(1);
        	return temp;
        }
        int carry = (temp[length - 1] + 1) / 10;
        if(carry == 0) {
        	++temp[length - 1];
        	return temp;
        }
        else {
        	temp[length - 1] = (temp[length - 1] + 1) % 10;
        	for(int i = length - 2; i >= 0; --i) {
        		int num = temp[i];
        		temp[i] = (num + carry) % 10;
        		carry = (num + carry) / 10;
        		if(carry == 0) {

        			return temp;
        		}
       		}
       		temp.insert(temp.begin(), 1);
       		return temp;
        }
        
    }
};
int main(int argc, char const *argv[])
{
	vector<int> digits;
	digits.push_back(8);
	digits.push_back(9);
	digits.push_back(9);
	digits.push_back(9);

	Solution *s = new Solution();
	vector<int> result = s->plusOne(digits);
	for(int i = 0; i < result.size(); ++i) {
		cout<<result[i];
	}
	cout<<endl;
	return 0;
}