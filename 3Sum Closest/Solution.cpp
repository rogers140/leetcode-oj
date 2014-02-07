#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <limits>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		sort(num.begin(), num.end()); 
		int ret;
		if (target > 0)
			ret = numeric_limits<int>::max();
		else 
			ret = numeric_limits<int>::min() + 1;
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
				//cout<<sum<<endl;
				if (abs(sum - target) < abs(ret - target)) {
					ret = sum;
				}
				if (sum > target) {
					--z;
				}
				if (sum < target) {
					++y;
				}
				if (sum == target) {
					return target;
				}
			}
		}
		return ret;
	}
};

int main(int argc, char const *argv[]) {
	vector<int> num;
	int target = 0;
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);
	// num.push_back(3);
	// num.push_back(-4);
	Solution *s = new Solution();
	cout<<s->threeSumClosest(num, target)<<endl;
	return 0;
}