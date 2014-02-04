#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int> &height) {
        int high = height.size() - 1;
        int low = 0;
        int maxArea = 0;
        while (low < high) {
        	maxArea = max(maxArea, (high - low) * min(height[low], height[high]));
        	if (height[low] < height[high]) {
        		low++;  // we ignore to compute area[low, high-k] (k=1,2...)
        				// because here height is limited by low, 
        				// the width of area[low, high -k] is shorter while height could not be longer
        	}
        	else {
        		high--;
        	}
        }
        
        return maxArea;
    }
};

int main(int argc, char const *argv[]) {
	vector<int> height;
	Solution *s = new Solution();
	height.push_back(3);
	height.push_back(4);
	height.push_back(1);
	height.push_back(7);
	height.push_back(2);
	height.push_back(9);
	height.push_back(4);
	height.push_back(6);
	cout<<"the max area of test is :"<<s->maxArea(height)<<endl;
	return 0;
}