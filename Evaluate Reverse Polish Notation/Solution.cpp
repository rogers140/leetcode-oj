#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		int result = 0;
		vector<int> stack;
		for (int i = 0; i < tokens.size(); ++i) {
      string str = tokens[i];
      if (str != "+" && str != "-" &&
      	  str != "*" && str != "/") {
      	stack.push_back(stoi(str));
      } else {
      	int second = stack.back();
      	stack.pop_back();
      	int first = stack.back();
      	stack.pop_back();
      	if (str == "+") result = first + second;
      	if (str == "-") result = first - second;
      	if (str == "*") result = first * second;
      	if (str == "/") result = first / second;
      	//cout<<first<<str<<second<<": "<<result<<endl;
      	stack.push_back(result);
      }
		}
		return stack.back();
	}
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	string str1[] = {"2", "1", "+", "3", "*"};
	string str2[] = {"4", "13", "5", "/", "+"};
	vector<string> test1(str1, str1 + 5);
	vector<string> test2(str2, str2 + 5);
	cout<<s->evalRPN(test1)<<endl;
	cout<<s->evalRPN(test2)<<endl;
	return 0;
}