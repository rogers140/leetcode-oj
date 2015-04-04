#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        unordered_map<int, int> hash;
        for(int i = 0; i < num.size(); ++i) {
        	if(hash.find(num[i]) != hash.end()) {
        		++hash[num[i]];
        		//cout<<"num:"<<num[i]<<", count:"<<hash[num[i]]<<endl;
        	}
        	else {
        		hash[num[i]] = 1;
        	}
        }
        //cout<<"size:"<<num.size()<<endl;
        unordered_map<int,int>::const_iterator it= hash.begin();
        for(; it != hash.end(); ++it) {
        	//cout<<it->first<<","<<it->second<<endl;
        	if(it->second > num.size() / 2) {
        		return it->first;
        	}
        }
    }
};
int main(int argc, char const *argv[])
{
	Solution *s = new Solution();
	int array1[] = {1, 2, 3, -10, 2, 4, 2, 8, 2, 2, 2, 2};
	vector<int> test1(array1, array1 + 12);
	cout<<s->majorityElement(test1)<<endl;
	return 0;
}
