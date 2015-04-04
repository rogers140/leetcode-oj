#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        typedef vector<int> quadruplet;
        vector<quadruplet> result;
        for (int a = num.size() - 1; a >= 3; --a) {
        	if (a < num.size() - 1 && num[a] == num[a + 1]) {
				continue;
			}
			for (int b = a -1; b >= 2; --b) {
				if (b < a-1 && num[b] == num[b+1]) {
					continue;
				}
				for (int c = 0, d = b - 1; c < d;) {
					if (c > 0 && num[c] == num[c - 1]) {
						++c;
						continue;
					}
					if (d < b - 1 && num[d] == num[d + 1]) {
						--d;
						continue;
					}
					int sum = num[a] + num[b] + num[c] + num[d];
					if (sum > target) {
						--d;
					}
					if (sum < target) {
						++c;
					}
					if (sum == target) {
						vector<int> tmp(4);
						tmp[0] = num[c];
						tmp[1] = num[d];
						tmp[2] = num[b];
						tmp[3] = num[a];
						result.push_back(tmp);
						++c;
						--d;
					}
				}
			}
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
	int target = 0;
	vector<int> num;
	num.push_back(1);
	num.push_back(0);
	num.push_back(-1);
	num.push_back(0);
	num.push_back(-2);
	num.push_back(2);
	Solution *s =  new Solution();
	vector<vector<int> > result = s->fourSum(num, target);
	return 0;
}