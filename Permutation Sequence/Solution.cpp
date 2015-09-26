#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        string result(n, '0');
        vector<int> array(n, 0);
        for(int i = 0; i < n; ++i) {
        	array[i] = i + 1;
        }
        vector<int> cacheOfN;
        int multiple = 1;
        cacheOfN.push_back(multiple);
        for(int i = 1; i < n; ++i) {
        	multiple = multiple * i;
        	//cout<<multiple<<endl;
        	cacheOfN.push_back(multiple);
        }
        if(k < 1 || k > n * cacheOfN[n - 1]) {
        	return result;
        }
        int index = 0;
        --k;
        while (index < n) {
        	int temp  = k / cacheOfN[n - index - 1];
        	result[index] += array[temp];
        	array.erase(array.begin() + temp, array.begin() + temp + 1);
        	k = k % cacheOfN[n - index - 1];
        	++index;
        }
        return result;
    }
};

class Solution1 {
public:
    string getPermutation(int n, int k) {
        // Calculates i!.
        vector<int> n_ex(n, 0);  // Stores i!
        vector<int> nums(n, 0);  // Stores 1, 2, 3, ..., n
        int ex = 1;
        for (int i = 1; i <= n; ++i) {
            ex *= i;
            n_ex[i - 1] = ex;
            nums[i - 1] = i;
        }
        return getPermutation_aux(n_ex, nums, k);
    }
    string getPermutation_aux(vector<int>& n_ex, vector<int>& nums, int k) {
        string result(nums.size(), '0');
        const int n = nums.size();
        int count = n;
        n_ex.pop_back();  // Not need to do with the last one.
        while (count > 1) {
            // cout<<"count: "<<count<<", k: "<<k;
            int size = n_ex.back();
            int index = (k - 1) / size;
            result[n - count] = '0' + nums[index];
            n_ex.pop_back();
            // cout<<", size: "<<size<<", index: "<<index<<endl;
            // cout<<nums.size()<<endl;
            nums.erase(nums.begin() + index);
            k = k - index * size;
            --count;
        }
        result[n - 1] = '0' + nums[0];
        return result;
    }
};

int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	cout<<s->getPermutation(4, 5)<<endl;
	return 0;
}