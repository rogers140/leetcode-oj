#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		// From both begin and end to the middle, if left can not move forward,
		// let right move back to gain more oil if possible
		int start = 0;
		int end = gas.size() - 1;
		int capacity = 0;
		while (start <= end) {
			if (capacity + gas[start] - cost[start] >= 0) {
				capacity += gas[start] - cost[start];
				++start;
			} else {  // Move pivot forward to make some possible gain of oil.
				capacity += gas[end] - cost[end];
				--end;
			}
		}
		if (capacity >= 0) {
			return start % gas.size();
		} else {
			return -1;
		}

	}
};
int main(int argc, char const* argv[]) {
	Solution *s = new Solution();
	int g[] = {1, 2};
	int c[] = {2, 1};
	vector<int> gas(g, g + 2);
	vector<int> cost(c, c + 2);
	cout<<s->canCompleteCircuit(gas, cost)<<endl;
	return 0;
}