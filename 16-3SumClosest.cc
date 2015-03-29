/**
 *  Given an array S of n integers, find three integers
 *  in S such that the sum is closest to a given number
 *  target. Return the sum of the three integers. You
 * 	may assume that each input would have exactly one
 *  solution.
 *  For example, given array S = {-1 2 1 -4}, and
 *  target = 1.
 *  The sum is closest to the target is 2. 
 *  (-1 + 2 + 1 = 2).
 */

 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;

 class Solution {
 public:
 	int threeSumClosest(vector<int> &num, int target) {
 		int n = num.size();
 		sort(num.begin(), num.end());
 		int res = 65535;
 		for(int i = 0;i < n - 2;i++) {
 			// ignore the duplicated element
 			if (i > 0 && num[i] == num[i - 1]) continue;
 			int a = num[i];
 			int start = i + 1;
 			int end = n - 1;
 			while(start < end) {
 				int b = num[start];
 				int c = num[end];
 				int left = abs(target - (a+b+c));
 				res = (res < left)?res;left;
 			} 
  		}
 		return 0;
 	}
 };

 int main(int argc, char * argv[]) {
 	Solution * sol = new Solution();
 	return 0;
 }