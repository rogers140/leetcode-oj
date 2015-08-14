#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int length = prices.size();
		if(length <= 0) 
			return 0;
		// record balance during ith step with 4 condition
		// 0: buy; 1: buy, sell;
		// 2: buy, sell, buy; 3: buy, sell, buy, sell; 
		int state_record[length][4];

		state_record[0][0] = -prices[0];
		state_record[0][1] = -prices[0];
		state_record[0][2] = -prices[0];
		state_record[0][3] = -prices[0];
		for (int i = 1; i < length; ++i) {
			state_record[i][0] = max(state_record[i - 1][0], -prices[i]);
			state_record[i][1] = max(state_record[i - 1][1],
				                       prices[i] + state_record[i - 1][0]);
			state_record[i][2] = max(state_record[i - 1][2],
				                       state_record[i - 1][1] - prices[i]);
			state_record[i][3] = max(state_record[i - 1][3],
				                       state_record[i - 1][2] + prices[i]);
		}
    int max_profit = max(state_record[length - 1][1], state_record[length - 1][3]);
    return max(0, max_profit);
	}
};

int main(int argc, char const *argv[])
{
	int prices_list[] = {2, 1, 3, 6, 5, 9, 3, 6};
	vector<int> prices(prices_list, prices_list + 8);
	Solution *s = new Solution();
	cout<<s->maxProfit(prices)<<endl;
	return 0;
}