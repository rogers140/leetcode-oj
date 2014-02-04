#include <stdio.h>
#include <iostream>
using namespace std;
//Manacher Algorithms
class Solution {
public:
    string longestPalindrome(string s) {
        string ModifiedStr = "$#";
        for (int i = 0; i < s.size(); i++) {
        	ModifiedStr = ModifiedStr + s[i] + "#";
        }
        int ModifiedStrSize = ModifiedStr.size();
        int *p =new int[ModifiedStrSize];//leetCode oj: int p[4000] = {0} is ok, in case of runtime error
        int mx = 0, id = 0;

        for (int i = 1; i < ModifiedStrSize; i++) {
        	if (mx > i) {
        		p[i] = (p[2 * id - 1] < (mx - i)) ? p[2 * id - 1] : (mx - i);
        	}
        	else {
        		p[i] = 1;
        	}
        	while (ModifiedStr[i - p[i]] == ModifiedStr[i + p[i]]) {
        		p[i]++;
        		if ((i - p[i]) < 0 || (i + p[i]) >= ModifiedStrSize) {
        			break;
        		}
        	}
        	p[i]--;
        	if (i + p[i] > mx) {
        		mx = i + p[i];
        		id = i;
        		
        	}
        }

        int maxlength = 0;
        int middleindex = 0;
        for (int i = 1; i < ModifiedStrSize; i++) {
        	if (p[i] > maxlength){
        		maxlength = p[i];
        		middleindex = i;
        	}
        }
        
        int start =  middleindex - maxlength;
        int end = middleindex + maxlength;
        string result = "";
        for (int i = start; i <= end; i++) {
        	if (ModifiedStr[i] != '#') {
            	result+=ModifiedStr[i];
        	}
    	}
    	delete[] p;
        return result;

    }
};
int main(int argc, char const *argv[]) {
	string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
	string result = (new Solution())->longestPalindrome(s);
	cout<<result<<endl; 
	return 0;
}