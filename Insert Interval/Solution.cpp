#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {} 
};
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    	if(intervals.size() == 0) {
    		intervals.push_back(newInterval);
    		return intervals;
    	}
    	int i = 0;
    	bool isLast = true;
        // Last is the special case.
        for(; i < intervals.size(); ++i) {
        	if(intervals[i].start > newInterval.start){
        		isLast = false;
        		break;
        	}
        }
        if(isLast) {
        	if(intervals[intervals.size() - 1].end < newInterval.start) {
        		intervals.push_back(newInterval);
        		return intervals;
        	}
        	else {
        		intervals[intervals.size() - 1].end = (newInterval.end > intervals[intervals.size() - 1].end) ? newInterval.end : intervals[intervals.size() - 1].end;
        		return intervals;
        	}
        }
        // Common cases.
        if(i > 0) {
        	if(intervals[i - 1].end > newInterval.end) {
        		return intervals;
        	}
        	else if(intervals[i - 1].end >= newInterval.start) {
        		intervals[i - 1].end = newInterval.end;
        		--i;
        	}
        	else {
        		intervals.insert(intervals.begin() + i, newInterval);
        	}
        }
        else {
        	intervals.insert(intervals.begin() + i, newInterval);
        }
        int j = i + 1;
        while(j < intervals.size()) {
        	if(intervals[j].start <= newInterval.end) {
        		if(intervals[j].end >= newInterval.end) {
        			intervals[i].end = intervals[j].end;
        			break;
        		}
        		++j;
        	}
        	else {
        		--j;
        		break;
        	}
        }
        if(j == intervals.size()) {
        	--j;
        }
        intervals.erase(intervals.begin() + i + 1, intervals.begin() + j + 1);
        return intervals;

    }
};
int main(int argc, char const *argv[])
{
	Interval i1(1, 2);
	Interval i2(3, 5);
	Interval i3(6, 7);
	Interval i4(8, 10);
	Interval i5(12, 16);
	Interval newInterval1(4, 9);
	vector<Interval> intervals1;
	intervals1.push_back(i1);
	intervals1.push_back(i2);
	intervals1.push_back(i3);
	intervals1.push_back(i4);
	intervals1.push_back(i5);	

	Solution *s = new Solution();
	vector<Interval> result1 = s->insert(intervals1, newInterval1);
	for(int i = 0; i < result1.size(); ++i) {
		cout<<"["<<result1[i].start<<", "<<result1[i].end<<"], ";
	}
	cout<<endl;


	Interval i6(1, 5);
	Interval i7(6, 8);
	Interval newInterval2(5, 6);	
	vector<Interval> intervals2;
	intervals2.push_back(i6);
	intervals2.push_back(i7);

	vector<Interval> result2 = s->insert(intervals2, newInterval2);
	for(int i = 0; i < result2.size(); ++i) {
		cout<<"["<<result2[i].start<<", "<<result2[i].end<<"], ";
	}
	cout<<endl;
	return 0;
}