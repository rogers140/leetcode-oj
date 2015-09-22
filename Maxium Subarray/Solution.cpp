#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        const int size = nums.size();
        vector<int> max_end(size, 0);  // Stores the largest sum that ends in i.
        max_end[0] = nums[0];
        for (int i = 1; i < size; ++i) {
            max_end[i] = max_end[i - 1] > 0 ? max_end[i - 1] + nums[i] : nums[i];
        }
        return *max_element(max_end.begin(), max_end.end());
    }
};
int main(int argc, char const *argv[])
{
	int A[9]={-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> input(A, A + 9);
	Solution *s = new Solution();
	cout<<s->maxSubArray(input)<<endl;
	return 0;
}