#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution{
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        unordered_map<int,int> mymap;
        int index1, index2;
        index1 = 0;
        index2 = 0;
        for (int i = 0; i < numbers.size(); i++) {
        	if (mymap.find(numbers[i]) == mymap.end()) {
        		mymap[target-numbers[i]] = i;
        	}
        	else {
        		index1 = ((mymap[numbers[i]] < i) ? mymap[numbers[i]] : i)+1;
        		index2 = ((mymap[numbers[i]] > i) ? mymap[numbers[i]] : i)+1;
        		result.push_back(index1);
        		result.push_back(index2);
        		break;
        	}
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
	int temp[4] = {2, 7, 11, 15};
    vector<int> numbers(temp, temp+4);
    vector<int> result=(new Solution())->twoSum(numbers, 26);
    cout<<result[0]<<", "<<result[1]<<endl;
    return 0;
}