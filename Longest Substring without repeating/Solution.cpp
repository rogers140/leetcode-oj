#include <stdio.h>
#include <iostream>
#include <unordered_map>
using namespace std;
//dynamic programming and hash
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const char *str = s.c_str();
        int maxlength = 0;
        int templength = 0;
        int start_index = 0;
        unordered_map<char, int> hashmap;
        for (int i = 0; i < s.size(); i++) {
        	if (hashmap.find(str[i]) == hashmap.end()) {
        		hashmap[str[i]] = i;
        		templength++;
        	}
        	else {
        		start_index = (start_index > hashmap[str[i]]) ? start_index : hashmap[str[i]];
        		templength = i - start_index;
        		hashmap[str[i]] = i;
        	}
        	if (templength > maxlength) {
        		maxlength = templength;
        	}
        }
        return maxlength;
    }
};

int main(int argc, char const *argv[]) {
	cout<<(new Solution())->lengthOfLongestSubstring("abacdeab")<<endl;
	return 0;
}