#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int shortest_len = strs[0].size();
        string shortest_str = strs[0];
        for (string str : strs) {
            if (str.size() < shortest_len) {
                shortest_len = str.size();
                shortest_str = str;
            }
        }
        int longest_length = shortest_str.size();
        for (string str : strs) {
            while (str.substr(0, longest_length) !=
                shortest_str.substr(0, longest_length) &&
                longest_length > 0) {
                --longest_length;
            }
            if (longest_length == 0) return "";
        }
        return shortest_str.substr(0, longest_length);
    }
};

int main(int argc, char const *argv[]) {
	Solution *s = new Solution();
	vector<string> str;
	str.push_back("goodmorning");
	str.push_back("goodevening");
	str.push_back("google");
	str.push_back("goohoo");
	str.push_back("goodboy");
	cout << s->longestCommonPrefix(str) << endl; 
	return 0;
}