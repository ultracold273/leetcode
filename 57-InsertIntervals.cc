/**
 * Given a set of non-overlapping intervals, insert a 
 * new interval into the intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted 
 * according to their start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] 
 * in as [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps 
 * with [3,5],[6,7],[8,10]. 
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

class Solution {
public:
	int findPosition(vector<Interval>& intervals, int num) {
		int left = 0;
		int right = intervals.size() - 1;
		while(left < right) {
			if (intervals[(left + right)/2].start > num) {
				right = (left + right)/2;
			}else{
				left = (left + right)/2;
			}
		}
		return right - 1;
	}

	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		int stPos = findPosition(intervals, newInterval.start);
		int edPos = findPosition(intervals, newInterval.end);
		vector<Interval> ret;
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
	intvals.push_back(Interval(6, 9));
	vector<Interval> retInt = sol->insert(intvals, Interval(2, 5));
	printInterval(retInt);
	vector<Interval> intval2;
	intval2.push_back(Interval(1, 2));
	intval2.push_back(Interval(3, 5));
	intval2.push_back(Interval(6, 7));
	intval2.push_back(Interval(8, 10));
	intval2.push_back(Interval(12, 16));
	retInt = sol->insert(intval2, Interval(4, 9));
	printInterval(retInt);
	return 0;
}
