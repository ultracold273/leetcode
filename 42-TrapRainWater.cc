
/**
 * Given n non-negative integers representing an elevation map 
 * where the width of each bar is 1, 
 * compute how much water it is able to trap after raining.
 *
 * For example,
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * 1. Find the highest bar
 * 2. Start from the left to the right
 */

class Solution {
public:
	int trap(vector<int>& height) {
		int totalRain = 0;
		vector<int>::iterator it, highest;
		// Find local maximum
		highest = height.begin();
		if (height.end() - height.begin() <= 2) return totalRain;
		for(it = height.begin();it != height.end();it++) {
			if (*it >= *highest) {
				highest = it;
			}
		}

		vector<int>::iterator prevHigh = height.begin();
		for(it = height.begin();it != highest + 1;it++) {
			if (*it >= *prevHigh) {
				totalRain += calulateRainDrop(prevHigh, it + 1);
				prevHigh = it;
			}
		}

		prevHigh = height.end() - 1;
		for(it = height.end() - 1;it != highest - 1;it--) {
			if(*it >= *prevHigh) {
				totalRain += calulateRainDrop(it, prevHigh + 1);
				prevHigh = it;
			}
		}
		return totalRain;
	}

	int calulateRainDrop(vector<int>::iterator st, vector<int>::iterator ed) {
		vector<int>::iterator it;
		int rainDrop = 0;
		int waterLevel = (*st > *(ed - 1))?*(ed - 1):*st;
		for(it = st;it != ed;it++) {
			if (*it < waterLevel) {
				rainDrop += waterLevel - *it;
			}
		}
		return rainDrop;
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	vector<int> ht (height, height + sizeof(height)/sizeof(int));
	cout << sol->trap(ht) << endl;
	return 0;
}
