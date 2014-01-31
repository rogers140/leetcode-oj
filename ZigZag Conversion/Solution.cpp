#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
    	if(nRows==1 || nRows==0){
    		return s;
    	}
        int vertical = nRows;
        int diagnoal = nRows - 2;
        int length = s.size();
        int NumOfCol = 0;
        if(length%(vertical+diagnoal) == 0){
        	NumOfCol = 2 * length/(vertical+diagnoal);
        }
        else{
        	NumOfCol = 2 * (length / (vertical + diagnoal))+ (length%(vertical+diagnoal))/vertical+1;
        }
        char *newstr = new char[nRows*NumOfCol];
        for (int i = 0; i<nRows*NumOfCol;i++){
        	newstr[i]=' ';
        }
        for (int i = 0; i < length; i++){
        	int temp1 = i % (vertical + diagnoal);
        	int temp2 = i / (vertical + diagnoal);
        	int row, col;
        	if(temp1 >= vertical){
        		row = vertical + diagnoal - temp1;
        		col = 2 * temp2 + 1;
        	}
        	else{
        		row = temp1;
        		col = 2 * temp2;
        	}
        	newstr[row*NumOfCol+col] = s[i];
        }
        string result = "";
        for (int i = 0; i<nRows*NumOfCol;i++){
        	if(newstr[i]!=' '){
        		result = result+newstr[i];
			}
        }
        delete[] newstr;
        return result;
    }
};

int main(int argc, char const *argv[]){
	cout<<(new Solution())->convert("PAYPALISHIRING",1)<<endl;
	return 0;
}