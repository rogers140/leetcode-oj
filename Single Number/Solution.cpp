#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
// Uses xor
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		const int size  = nums.size();
		int single = 0;
		for (int i = 0; i < size; ++i) {
			single ^= nums[i];
		}
		return single;
	}
};
int main(int argc, char const* argv[]) {
	int num_list[] = {2, 1, 2, 1, 3, 0, 0};
	vector<int> nums(num_list, num_list + 7);
	Solution *s = new Solution();
	cout<<s->singleNumber(nums)<<endl;
}