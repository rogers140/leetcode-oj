#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> record(nums.begin(), nums.end());
    int result = 1;
    for (int num: nums) {
    	if (record.find(num) != record.end()) {
    		int prev = num - 1;
    		int next = num + 1;
    		while(record.find(prev) != record.end()) record.erase(prev--);
    		while(record.find(next) != record.end()) record.erase(next++);
    		result = max(result, next - prev - 1);
    	}
    }
    return result;
  }
};
int main(int argc, char const* argv[]) {
	Solution *s = new Solution();
	// int a[6] = {100, 4, 200, 1, 3, 2};
	// vector<int> nums(a, a + 6);

	int a[7] = {2147483646,-2147483647,0,2,2147483644,-2147483645,2147483645};
	vector<int> nums(a, a + 7);
	cout<<s->longestConsecutive(nums)<<endl;
	return 0;
}