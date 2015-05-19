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

class Solution {
public:
	int trap(vector<int>& height) {
		int totalRain = 0;
		vector<int>::iterator it, st;
		// Find local maximum
		if (height.end() - height.begin() <= 2) return totalRain;
		bool startFlag = false;
		for(it = height.begin();it != height.end();it++) {
			if (it == height.begin()) {
				if (*it > *(it + 1)) {
					st = it;
					startFlag = true;
				}
			}else if(it == height.end() - 1) {
				if (*(it - 1) < *it) {
					if (startFlag)
						totalRain += calulateRainDrop(st, it + 1);
				}
			}else{
				if (*it > *(it + 1) && *it > *(it - 1)) {
					if (startFlag) {
						totalRain +=  calulateRainDrop(st, it + 1);
						st = it;
					}else{
						st = it;
						startFlag = true;
					}
				}
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
