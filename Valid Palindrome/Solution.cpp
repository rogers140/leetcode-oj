#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty()) return true;
		// Preprocesses the string.
		stripNonLetterChar(s);
		toLower(s);
		// Decides if it's palindrome.
		int head = 0;
		int tail = s.size() - 1;
		while (head <= tail) {
			if(s[head] != s[tail]) {
				return false;
			}
			++head;
			--tail;
		}
		return true;
	}
	void stripNonLetterChar(string& s) {
		for (int i = 0; i < s.size(); ++i) {
			// Changes every non alphanumeric char into space.
			if (!((s[i] >= 'a' && s[i] <= 'z') ||
				    (s[i] >= 'A' && s[i] <= 'Z') ||
				    (s[i] >= '0' && s[i] <= '9'))) {
				s[i] = ' ';
			}
		}
		// Strips empty spaces;
		size_t index;
		while((index = s.find(' ')) != string::npos) {
			s.erase(s.begin() + index);
		}
	}
	void toLower(string& s) {
		for (int i = 0; i < s.size(); ++i) {
			if(s[i] >= 'A' &&  s[i] <= 'Z') {
				s[i] -= 'Z' - 'z';
			}
		}
	}
};
 
int main(int argc, char const *argv[]) {
	string s1 = "A man, a plan, a canal: Panama";
	string s2 = "race a car";
	Solution* s = new Solution();
	cout<<s->isPalindrome(s1)<<endl;
	cout<<s->isPalindrome(s2)<<endl;
	cout<<s->isPalindrome("")<<endl;
	return 0;
}