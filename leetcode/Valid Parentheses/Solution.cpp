#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
    	vector<char> stack;
    	if (s.size() == 0) {
    		return true;
    	}
        for (int i = 0; i < s.size(); ++i) {
        	char c = s[i];
        	switch (c) {
        		case '(':
        			stack.push_back('(');
        			break;
        		case '[':
        			stack.push_back('[');
        			break;
        		case '{':
        			stack.push_back('{');
        			break;
        		case ')':
					if (stack.empty() || stack.back() != '(') {
						return false;
					}
					stack.pop_back();
					break;
				case ']':
					if (stack.empty() || stack.back() != '[') {
						return false;
					}
					stack.pop_back();
					break;
				case '}':
					if (stack.empty() || stack.back() != '{') {
						return false;
					}
					stack.pop_back();
					break;
				default:
					return false;
        	}
        }
        if (stack.size() != 0) {
        	return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
	Solution *s = new Solution();
	cout<<s->isValid(")}{({))[{{[}")<<endl;
	return 0;
}