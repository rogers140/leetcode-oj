#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1) return;
		int endOfIncrease = 0;
		for (int i = 0; i < nums.size() - 1; ++i) {
			if (nums[i] < nums[i + 1])
				endOfIncrease = i;
		}
		if (endOfIncrease > 0) {
			int swapIndex = nums.size() - 1;
			while (swapIndex > endOfIncrease - 1 &&
				     nums[swapIndex] <= nums[endOfIncrease])
				--swapIndex;
			swap(nums[endOfIncrease], nums[swapIndex]);
		}
		sort(nums.begin() + endOfIncrease + 1, nums.end());
	}
};
int main(int argc, char const *argv[])
{
	int a[] = {1, 3, 2, 4};
	vector<int> nums(a, a + 4);
	Solution *s = new Solution();
	s->nextPermutation(nums);
	for (int i = 0; i < nums.size(); ++i) {
		cout<<nums[i]<<", ";
	}
	cout<<endl;
	return 0;
}