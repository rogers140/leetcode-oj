#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
/*
The method I used was to map the characters and how many are in the substring vs how many are needed. 
If all the values are non-negative, then you can remove characters from the start of the substring until you reach a negative, 
and if there's a negative, you expand the end of the substring until it is 0 again. 
You continue this until you've reached the end of S, and then remove characters until you have a negative count for one of the characters.
*/
class Solution {
public:
    string minWindow(string S, string T) {
        int lengthOfS = S.length();
        int lengthOfT = T.length();
        int map[256] = {0}; //store with ASCII
        int countOfNegative = 0;
        for(int i = 0; i < lengthOfT; ++i) {
        	--map[T[i]];
        }
        for(int i = 0; i < 256; ++i) {
        	if(map[i] < 0) {
        		++countOfNegative;
        	}
        }
        int minmunWindowSize = lengthOfS;
        int minStart = 0;
        int minEnd = lengthOfS - 1;
        bool found = false;
        int start = 0; 
        int end = -1;
        while(start != lengthOfS && end != lengthOfS) {
        	if(countOfNegative != 0) {
        		++end;
        		char current = S[end];
        		++map[current];
        		if(map[current] == 0) {
        			--countOfNegative;
        		}
        	}
        	else {
        		found = true;
        		int currentWindowSize = end - start + 1;
        		if(currentWindowSize < minmunWindowSize) {
        			minmunWindowSize = currentWindowSize;
        			minStart = start;
        			minEnd = end;
        		}
        		++start;
        		char removed = S[start - 1];
        		--map[removed];
        		if(map[removed] < 0) {
        			++countOfNegative;
        		}
        	}
        }
        if(countOfNegative == 0) { 
        	//if end reach the end of the S, and countOfNegative is 0, move start forward until negative appears
        	found = true;
        	while(start != lengthOfS) {
        		int currentWindowSize = end - start + 1;
        		if(currentWindowSize < minmunWindowSize) {
        			minmunWindowSize = currentWindowSize;
        			minStart = start;
        			minEnd = end;
        		}
        		++start;
        		char removed = S[start - 1];
        		--map[removed];
        		if(map[removed] < 0) {
        			++countOfNegative;
        			break;
        		}
        	}
        }
        if(found) {
        	return S.substr(minStart, minmunWindowSize);
        }
        else {
        	return "";
        }
        
    }
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	string S = "aaaa";
	string T = "aa";
	cout<<s->minWindow(S, T)<<endl;	
	return 0;
}
