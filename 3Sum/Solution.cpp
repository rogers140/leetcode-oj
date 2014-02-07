#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
    	typedef vector<int> triplet;
		sort(num.begin(), num.end()); 
		vector<triplet> result;
		for (int x = num.size() - 1; x >= 2; --x) {
			if (x < num.size() - 1 && num[x] == num[x + 1]) {
				continue;
			}
			for (int y = 0, z = x -1; y < z;) {
				if (y > 0 && num[y] == num[y - 1]) {
					++y;
					continue;
				}
				if (z < x-1 && num[z] == num[z + 1]) {
					--z;
					continue;
				}
				int sum = num[x] + num[y] + num[z];
				if (sum > 0) {
					--z;
				}
				if (sum < 0) {
					++y;
				}
				if (sum == 0) { //s == 0
					triplet temp(3);
					temp[0] = num[y];
					temp[1] = num[z];
					temp[2] = num[x];
					result.push_back(temp);
					++y;
					--z;
				}
			}
		}
		return result;
    }
};

int main(int argc, char const *argv[]) {
	Solution *s = new Solution();
	vector<int> num;
	num.push_back(-1);
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);
	num.push_back(-1);
	num.push_back(4);
	vector<vector<int> > result = s->threeSum(num);
	return 0;
}