#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = INT_MAX;
        for (int p : prices) {
        	minPrice = std::min(minPrice, p);
        	maxProfit = std::max(p - minPrice, maxProfit);
        }
        return maxProfit;
    }
};
int main(int argc, char const *argv[])
{
	int price_list[8] = {3, 2, 4, 9, 7, 1, 8, 6};
	vector<int> prices(&price_list[0], &price_list[8]);
	Solution *s = new Solution();
	cout<<s->maxProfit(prices)<<endl;
	return 0;
}