/**
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18]. 
 *
 * O(n log n) algorithm
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool compareIntervalByStart(Interval& a, Interval& b) {
	return (a.start < b.start);
}

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), compareIntervalByStart);
		vector<Interval> ret;
		for (int i = 0;i < (int) intervals.size();i++) {
			if(ret.size() == 0) {
				ret.push_back(intervals[i]);
			}else if (intervals[i].start > ret[ret.size() - 1].end) {
				ret.push_back(intervals[i]);
			}else {
				if(intervals[i].end > ret[ret.size() - 1].end) {
					ret[ret.size() - 1].end = intervals[i].end;
				}
			}
		}
		return ret;
	}
};

void printInterval(vector<Interval> & nums) {
	for(int i = 0;i < (int) nums.size();i++) {
		cout << "[" << nums[i].start << "," << nums[i].end << "],";
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	Solution * sol = new Solution();
	vector<Interval> intvals;
	intvals.push_back(Interval(1, 3));
	intvals.push_back(Interval(2, 6));
	intvals.push_back(Interval(8, 10));
	intvals.push_back(Interval(15, 18));
	vector<Interval> retInt = sol->merge(intvals);
	printInterval(retInt);
}
