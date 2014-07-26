#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	string countAndSay(int n) {
		if (n <= 1) {
			return "1";
		}
		string previous = countAndSay(n - 1);
		string result = "";
		int index = 1;
		int length = previous.length();
		int count = 1;
		if (length == 1) {
			return "11";
		}
		while(index < length) {
			char current_char = previous.at(index);
			char last_char = previous.at(index - 1);
			//cout<<last_char<<endl;
			if (current_char == last_char) {
				++count;
				if (index == length - 1) {//last one
					char temp = count + 48;
					result.append(1,temp);
					result.append(1, last_char);
					return result;
				}
			}
			else {
				char temp = count + 48;
				result.append(1,temp);
				result.append(1, last_char);
				count = 1;
				if (index == length - 1) {
					result.append("1");
					result.append(1, current_char);
					return result;
				}
			}
			++index;
		}
		return result;
	}
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	cout<<s->countAndSay(1)<<endl;
	cout<<s->countAndSay(2)<<endl;
	cout<<s->countAndSay(3)<<endl;
	cout<<s->countAndSay(4)<<endl;
	return 0;
}