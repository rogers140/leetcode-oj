#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1) return;
		int endOfIncrease = 0;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i - 1] < nums[i])
				endOfIncrease = i;
		}
		if (endOfIncrease > 0) {
			int swapIndex = nums.size() - 1;
			while (swapIndex > endOfIncrease - 1 &&
				     nums[swapIndex] <= nums[endOfIncrease - 1])
				--swapIndex;
			swap(nums[endOfIncrease - 1], nums[swapIndex]);
		}
		sort(nums.begin() + endOfIncrease, nums.end());
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