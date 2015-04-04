#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(word.size() == 0) {
            return true;
        }
        unordered_map<char, vector<pair<int, int> > > charTable;
        vector<pair<int, int> > positionStack; //store positions which has been selected
        vector<vector<int> > used; //to avoid the used position
        //build hashtable and used table
        for(int i = 0; i < board.size(); ++i) {
            vector<int> rowForUsed;
        	for(int j = 0; j < board[i].size(); ++j) {
        		pair<int, int> position(i, j);
        		char c = board[i][j];
        		if(charTable.find(c) == charTable.end()) {//not in board
        			vector<pair<int, int> > temp;
        			temp.push_back(position);
        			charTable[c] = temp;
        		}
        		else {
        			charTable[c].push_back(position);
        		}
                rowForUsed.push_back(0);//not used
        	}
            used.push_back(rowForUsed);
        }
        return exist_aux(charTable, word, positionStack,used);
    }

    bool exist_aux(unordered_map<char, vector<pair<int, int> > > &charTable, string word, vector<pair<int, int> > &stack, vector<vector<int> > &used) {
        int index = stack.size();//the char index of word
        if(index == word.size()) {
            return true;
        }
        if(index == 0) {//first one
            char current = word[index];
            if(charTable.find(current) != charTable.end()) { //found one
                vector<pair<int, int> > possiblePos = charTable[current];
                for(int i = 0; i < possiblePos.size(); ++i) {
                    used[possiblePos[i].first][possiblePos[i].second] = 1;
                    stack.push_back(possiblePos[i]);
                    if(exist_aux(charTable, word, stack, used)){//recursive
                        return true;
                    }
                    else {
                        used[possiblePos[i].first][possiblePos[i].second] = 0;
                        stack.pop_back();
                    }    
                }
                return false;
            }
            else {
                return false;
            }       
        }
        if(index == word.size() - 1) {
            //last char to be decided
            char current = word[index];
            pair<int, int> lastPos = stack[index - 1];
            if(charTable.find(current) != charTable.end()) { //found one
                vector<pair<int, int> > possiblePos = charTable[current];
                for(int i = 0; i < possiblePos.size(); ++i) {
                    if(used[possiblePos[i].first][possiblePos[i].second] == 0 && isNeighbor(lastPos, possiblePos[i])) {
                        used[possiblePos[i].first][possiblePos[i].second] = 1;
                        stack.push_back(possiblePos[i]);
                        return true;
                    }
                }
                //not neighbor
                return false;
            }
            else {
                return false;
            }           
        }
        //general situation
        char current = word[index];
        pair<int, int> lastPos = stack[index - 1];
        if(charTable.find(current) != charTable.end()) {
            vector<pair<int, int> > possiblePos = charTable[current];
            for(int i = 0; i < possiblePos.size(); ++i) {
                if(used[possiblePos[i].first][possiblePos[i].second] == 0 && isNeighbor(lastPos, possiblePos[i])) {
                    used[possiblePos[i].first][possiblePos[i].second] = 1;
                    stack.push_back(possiblePos[i]);
                    if(exist_aux(charTable, word, stack, used)) {
                        return true;
                    }
                    else {
                        stack.pop_back();
                        used[possiblePos[i].first][possiblePos[i].second] = 0;
                    }
                }
            }
        }
        else{
            return false;
        }
        return false;
    }

    bool isNeighbor(pair<int, int> positionOne, pair<int, int> positionTwo) {
    	if(positionOne.first == positionTwo.first) {
    		if(abs(positionOne.second - positionTwo.second) == 1) {
    			return true;
    		}
    	}
    	else if(positionOne.second == positionTwo.second) {
    		if(abs(positionOne.first - positionTwo.first) == 1) {
    			return true;
    		}
    	}
    	else {
    		return false;
    	}
        return false;
    }
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
    char row1[] = {'A', 'B', 'C', 'E'};
    char row2[] = {'S', 'F', 'C', 'S'};
    char row3[] = {'A', 'D', 'E', 'E'};
    vector<char> rowOne(row1, row1 + 4);
    vector<char> rowTwo(row2, row2 + 4);
    vector<char> rowThree(row3, row3 + 4);
    vector<vector<char> > board;
    board.push_back(rowOne);
    board.push_back(rowTwo);
    board.push_back(rowThree);

    cout<<s->exist(board, "ADFBCS")<<endl;
	return 0;
}