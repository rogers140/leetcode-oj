#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	void reverseWords(string &s) {
		preprocess(s);
		// cout<<"|"<<s<<"|"<<endl;
		// Reverses each word and then reverse whole sentence
		if(s.empty())
			return;
		int start = 0;
		int end = 0;
		while (end != s.size()) {
			// Finds first non-empty char
			while (s[start] == ' ') ++start;
			end = start;
			while (s[end] != ' ' && end < s.size()) ++end;
			end = end - 1;  // Becasue now end points to a space.
			reverse(s, start, end);
			start = end + 1;
			end = start;
		}
		reverse(s, 0, s.size() - 1);
	}
	void reverse(string& s, int start, int end) {
		if (start == end) return;
		while (start < end) {
			char temp = s[start];
			s[start] = s[end];
			s[end] = temp;
			++start;
			--end;
		}
	}
	void preprocess(string& s) {
		if (s.empty()) return;
		// Delete head and tail spaces.
		int start = 0;
		while (s[start] == ' ') ++start;
		s.erase(0, start);
		int end = s.size() - 1;
		int count = 0;
		while(s[end] == ' ') {
			--end;
			++count;
		}
		if (count != 0)
			s.erase(end + 1, count);
		// cout<<"|"<<s<<"|"<<endl;
		// Shrinks multiple space into one.
		start = 0;
		end = 0;
		count = 0;
		while (1) {
			int size = s.size();
			while (start < size && s[start] != ' ')
				++start;
			//cout<<start<<", ";
			if (start >= size) break;
			// Now start points to the first space
			end = start + 1;
			int count = 0;
			while (end < size && s[end] == ' ') {
				++count;
				++end;
			}
			if (count != 0)
				s.erase(start + 1, count);
			start += 1;  // Now start moves to next non-empty char.
			//cout<<start<<endl;
		}
	}
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();

	string str1 = "   a   b  c d   e  ";
	s->reverseWords(str1);
	cout<<"|"<<str1<<"|"<<endl;
	return 0;
}
