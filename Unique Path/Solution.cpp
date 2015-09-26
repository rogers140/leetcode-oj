#include <iostream>
using namespace std;
class Solution {
public:
  int uniquePaths(int m, int n) {
    --m;
    --n;
    long result = 1;
    for (int i = 1; i <= m; ++i) {
      result *= n + i;
      result /= i;
    }
    return (int)result;
  }
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	cout<<s->uniquePaths(27, 5)<<endl;
	return 0;
}