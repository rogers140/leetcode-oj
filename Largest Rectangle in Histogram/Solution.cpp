#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
//we need to calculate every area for each bar x as smallest bar
//and choose the largest area
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        vector<int> stack;
        int largestArea = 0;
        int i = 0;
        while(i < height.size()) {
        	if(stack.size() == 0 || height[i] > height[stack.back()]) {
        		stack.push_back(i);
        		++i;
        	}
        	else {
        		int top = stack.back();
        		stack.pop_back();
        		int currentArea = height[top] * (stack.empty() ? i : i - stack.back() - 1);
        		if(largestArea < currentArea) {
        			largestArea = currentArea;
        		}
        	}
        }
        while(!stack.empty()) {
        	int top = stack.back();
        	stack.pop_back();
        	int currentArea = height[top] * (stack.empty() ? i : i - stack.back() - 1);
        	if(largestArea < currentArea) {
        		largestArea = currentArea;
        	}
        }
        return largestArea;
    }
};
int main(int argc, char const *argv[])
{
	int A[] = {2, 1, 5, 6, 2, 3};
	vector<int> height(A, A + 6);
	Solution *s = new Solution();
	cout<<s->largestRectangleArea(height)<<endl;
	return 0;
}