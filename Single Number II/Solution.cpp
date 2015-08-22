#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int b1 = 0;
    int b0 = 0;
    for (int num : nums){
      int nb0 = (~b1 & b0 & ~num) | (~b1 & ~b0 & num);
      int nb1 = (b1 & ~b0 & ~num) | (~b1 & b0 & num) ;
			b0 = nb0;
      b1 = nb1;
    }
    return b0;
	}
};
int main(int argc, char const* argv[]) {
	int num_list[] = {2, 1, 2, 2, 3, 3, 3};
	vector<int> nums(num_list, num_list + 7);
	Solution *s = new Solution();
	cout<<s->singleNumber(nums)<<endl;
}