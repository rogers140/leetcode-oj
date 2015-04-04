#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
bool intervalCompare(Interval &first, Interval &second) {
	return first.start < second.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.size() < 2) {
        	return intervals;
        }
        sort(intervals.begin(), intervals.end(), intervalCompare);
        int j = 0;
        for(int i = 1; i < intervals.size(); ++i) {
        	if(intervals[i].start <= intervals[j].end) {//overlap
        		intervals[j].end = (intervals[i].end > intervals[j].end) ? intervals[i].end : intervals[j].end;
        	}
        	else{
        		++j; //put every interval that can not be merged into the index j
        		intervals[j].start = intervals[i].start;
        		intervals[j].end = intervals[i].end;

        	}
        }
        intervals.erase(intervals.begin() + 1 + j, intervals.end());
        return intervals;

    }
};
int main(int argc, char const *argv[])
{
	Interval i1(1, 3);
	Interval i2(2, 6);
	Interval i3(8, 10);
	Interval i4(15, 18);
	vector<Interval> intervals;
	intervals.push_back(i1);
	intervals.push_back(i2);
	intervals.push_back(i3);
	intervals.push_back(i4);

	Solution *s = new Solution();
	vector<Interval> result = s->merge(intervals);
	for(int i = 0; i < result.size(); ++i) {
		cout<<"["<<result[i].start<<", "<<result[i].end<<"], ";
	}
	cout<<endl;
	return 0;
}