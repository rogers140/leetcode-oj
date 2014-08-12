#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        int wordNum = words.size();
    	if(wordNum == 0 || L == 0) {
    		vector<string> result;
    		result.push_back("");
    		return result;
    	}
        vector<vector<int> > store;
        vector<int> line;
        int leftLength = L;
        for(int i = 0; i < wordNum; ++i) {
        	int length = words[i].size();
        	if(leftLength == L) {//the first word of a line
        		if(leftLength >= length) {
        			line.push_back(i);
        			leftLength = leftLength - length;
        			if(i == wordNum - 1) {//the last word
        				store.push_back(line);
        			}
        		}
        	}
        	else {//not the first, so we should add at least one space before the word
        		++length;
        		if(leftLength >= length) {
        			line.push_back(i);
        			leftLength = leftLength - length;
        			if(i == wordNum - 1) {//the last word
        				store.push_back(line);
        			}
        		}
        		else {
        			store.push_back(line);
        			leftLength = L;
        			line.clear();
        			--i; // must stepback to see if the next line could fill this word
        		}

        	}
        }
        vector<string> result;
        for(int i = 0; i < store.size(); ++i) { //for each line
        	int numOfSpace = L;
        	int wordOfLine = store[i].size();

        	if(wordOfLine == 1) { //only one word in this line
        		int index = store[i][0];
        		string justifiedLine = words[index];
        		justifiedLine.append((L - words[index].size()), ' ');
        		result.push_back(justifiedLine);
        		continue;
        	}

        	//else
        	for(int j = 0; j < wordOfLine; ++j) {
        		int index = store[i][j];
        		numOfSpace = numOfSpace - words[index].size();
        	}
        	if(i == store.size() - 1) {//last line
        		string justifiedLine = words[(store[i][0])];
        		for(int j = 1; j < wordOfLine; ++j) {
        			int index = store[i][j];
        			justifiedLine.append(1, ' ');
        			justifiedLine.append(words[index]);    			
        			--numOfSpace;
        		}
        		justifiedLine.append(numOfSpace, ' ');
        		result.push_back(justifiedLine);
        	}
        	else {
        		int evenNum = numOfSpace / (wordOfLine - 1);
        		vector<int> spaceCount(wordOfLine - 1, evenNum);
        		int leftOver = numOfSpace % (wordOfLine - 1);
        		for(int ptr = 0; ptr < leftOver; ++ptr) {
        			++spaceCount[ptr];
        		}

        		string justifiedLine = words[(store[i][0])];
        		for(int j = 1; j < wordOfLine; ++j) {
        			int index = store[i][j];
        			justifiedLine.append(spaceCount[j - 1], ' ');
        			justifiedLine.append(words[index]);			
        		}
        		result.push_back(justifiedLine);
        	}
        	
        }


        return result;

    }
};
int main(int argc, char const *argv[])
{
	vector<string> words;
	words.push_back("Don't");
	words.push_back("go");
	words.push_back("around");
	words.push_back("saying");
	words.push_back("the");
	words.push_back("world");
	words.push_back("owes");
	words.push_back("you");
	words.push_back("a");
	words.push_back("living;");
	words.push_back("the");
	words.push_back("world");
	words.push_back("owes");
	words.push_back("you");
	words.push_back("nothing;");
	words.push_back("it");
	words.push_back("was");
	words.push_back("here");
	words.push_back("first.");	

	Solution *s = new Solution();
	vector<string> result = s->fullJustify(words, 30);
	for(int i = 0; i < result.size(); ++i) {
		cout<<"\""<<result[i]<<"\""<<endl;
    }
	return 0;
}