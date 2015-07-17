#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	// add up all the increase
    	int max = 0;
        for (int i = 1; i < prices.size(); ++i) {
        	if (prices[i] >= prices[i - 1]) {
        		max += prices[i] - prices[i - 1];
        	}
        }
        return max;
    }
};
int main(int argv, char const *args[]) {
	int price_list[9] = {1, 3, 2, 5, 7, 8, 3, 2, 5};
	vector<int> prices(&price_list[0], &price_list[9]);
	Solution *s = new Solution();
	cout<<s->maxProfit(prices)<<endl;
}