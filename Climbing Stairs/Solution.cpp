#include <stdio.h>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        //using dp method, with first three steps as base.
        if(n == 0) {
        	return 1;
        }
        if(n == 1) {
        	return 1;
        }
        if(n == 2) {
        	return 2;
        }
        unordered_map<int, int> hashmap;
        hashmap[0] = 1;
        hashmap[1] = 1;
        hashmap[2] = 2;
        int i = 3;
        while(i <= n) {
        	if(hashmap.find(i - 1) != hashmap.end() && hashmap.find(i - 2) != hashmap.end()){
        		hashmap[i] = hashmap[i - 1] + hashmap[i - 2];
        	}
        	++i;
        }
        return hashmap[n];
    }
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	cout<<s->climbStairs(44)<<endl;
	return 0;
}