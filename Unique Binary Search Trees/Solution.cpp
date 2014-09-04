#include <stdio.h>
#include <iostream>
#include <unordered_map>
using namespace std;
//using DP to avoid duplicate calculate
//or you can have a formula ans  = ans * 2 * (2 * i - 1) / (i + 1);
class Solution {
public:
	int numTrees(int n) {
		unordered_map<int, int> hashmap;
		hashmap[0] = 1;
		hashmap[1] = 1; //store total number of unique BST for n
		if(n == 0 || n == 1) {
			return n;
		}
		for(int i = 2; i <= n; ++i) {
			//calculate unique BST when there is i numbers
			int total = 0;
			for(int j = 1; j <= i; ++j) {
				//calculate uniques BST when j is root
				total += (hashmap[j - 1] * hashmap[i - j]); //multiply left and right
			}
			hashmap[i] = total;
		}
		return hashmap[n];
	}
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	cout<<s->numTrees(4)<<endl;
	return 0;
}