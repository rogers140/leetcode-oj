#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> pathStack = SplitString(path, '/');
        if(pathStack.size() == 0) {
        	return "/";
        }
        if(pathStack.size() == 1) {
        	if(pathStack[0] == ".."){
        		return "/";
        	}
        	else if(pathStack[0] == ".") {
        		return "/";
        	}
        	else {
        		string temp = "/";
        		temp.append(pathStack[0]);
        		return temp;
        	}
        }
        vector<string> cache;
        for(int i = 0; i < pathStack.size(); ++i) {
        	string current = pathStack[i];
        	if(current == ".") {
        		continue;
        	}
        	else if(current == "..") {
        		if(cache.size() != 0) {
        			cache.pop_back();
        		}
        	}
        	else {
        		cache.push_back(current);
        	}
        }
        string result = "";
        for(int i = 0; i < cache.size(); ++i) {
        	result.append("/");
        	result.append(cache[i]);
        }
        if(result == "") {
        	result = "/";
        }
        return result;
    }
	vector<string> SplitString(string &src, char spliter)
	{
		vector<string> result;
		int old = -1;
		int current = 0;
		for(; current < src.size(); ++current) {
			if(src[current] == spliter) {
				if(old + 1 == current) {
					++old;
					continue;
				}
				else {
					string temp = src.substr(old + 1, current - old - 1);
					result.push_back(temp);
					old = current;
				}
			}
			else if(current == src.size() - 1) {
				string temp = src.substr(old + 1, current - old);
				result.push_back(temp);
			}
		}
		return result;
    }
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	string path = "/../";
	string result = s->simplifyPath(path);
	cout<<result<<endl;
	return 0;
}