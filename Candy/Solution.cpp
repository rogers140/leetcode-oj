#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
  int candy(vector<int>& ratings) {
  	// Two way checking.
    int i, n, sum;
    n = ratings.size();
    vector<int> candy(n, 1);
    for(i = 1; i < n; i++){
      if(ratings[i] > ratings[i - 1]) {
        candy[i] = candy[i - 1] + 1;
      }
    }
    sum = candy[n - 1];
    for(i = n - 2; i >= 0; i--){
      if(ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1]){
        candy[i] = candy[i + 1] + 1;
      }
      sum += candy[i];
    }
    return sum;
  }
};
int main(int argc, char const* argv[]) {
	Solution *s = new Solution();
	int a[] = {2, 3, 1, 2, 9, 7, 6, 5, 5, 6};
	vector<int> ratings1(a, a + 10);
	cout<<s->candy(ratings1)<<endl;

	int b[] = {1, 2, 4, 4, 3};
	vector<int> ratings2(b, b + 5);
	cout<<s->candy(ratings2)<<endl;
	return 0;
}