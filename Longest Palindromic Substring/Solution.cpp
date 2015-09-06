#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Manacher Algorithms
class Solution {
public:
    string longestPalindrome(string s) {
        string modifiedStr = "$#";
        for (int i = 0; i < s.size(); i++) {
        	modifiedStr = modifiedStr + s[i] + "#";
        }
        const int modifiedStrSize = modifiedStr.size();
        // p stores the palondrome right length with mid point i.
        vector<int> p(modifiedStrSize, 0);
        // maxRight is the right most position the palindromes ever touches
        // id is the current mid point of a palindromes who reaches maxRight.
        int maxRight = 0, id = 0;

        for (int i = 1; i < modifiedStrSize; i++) {
        	if (maxRight > i) {
                // Three conditions together
        		p[i] = min(p[2*id - i], p[id] + id - i);
        	}
        	else {
        		p[i] = 1;
        	}
        	while (modifiedStr[i - p[i]] == modifiedStr[i + p[i]]) {
        		p[i]++;
        		if ((i - p[i]) < 0 || (i + p[i]) >= modifiedStrSize) {
        			break;
        		}
        	}
        	p[i]--;  // delete the bad 1.
        	if (i + p[i] > maxRight) {
        		maxRight = i + p[i];
        		id = i;
        		
        	}
        }
        int maxlength = 0;
        int middleindex = 0;
        for (int i = 1; i < modifiedStrSize; i++) {
        	if (p[i] > maxlength){
        		maxlength = p[i];
        		middleindex = i;
        	}
        }
        
        int start =  middleindex - maxlength;
        int end = middleindex + maxlength;
        string result = "";
        for (int i = start; i <= end; i++) {
        	if (modifiedStr[i] != '#') {
            	result += modifiedStr[i];
        	}
    	}
        return result;
    }
};
int main(int argc, char const *argv[]) {
	string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
	string result = (new Solution())->longestPalindrome(s);
	cout<<result<<endl; 
	return 0;
}