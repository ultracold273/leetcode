/**
 *  Given an array S of n integers, are there elements
 *  a, b, c in S such that a + b + c = 0?
 *  Find all unique triplets in the array which gives
 *  the sum of zero.
 *  Note:
 *  Elements in a triplet (a, b, c) must be in
 *  non-descending order. (ie. a <= b <= b)
 *  The solution set must not contain duplicate
 *  triplets.
 *  For example, given array S = {-1 0 1 2 -1 -4},
 *  A solution set is:
 *  (-1, 0, 1), (-1, -1, 2)
 */

 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;

/*
 Check the wikipedia page: 3SUM
 http://en.wikipedia.org/wiki/3Sum
*/
 class Solution
 {
 public:
 	vector<vector<int> > threeSum(vector<int> &num) {
 		vector<vector<int> > res;
 		int totalNum = num.size();
		sort(num.begin(), num.end());
		for(int i = 0; i < totalNum - 2; i++) {
			if(i > 0 && num[i-1] == num[i]) continue;
			int a = num[i];
			int start = i + 1;
			int end = totalNum - 1;
			while(start < end) {
				int b = num[start];
				int c = num[end];
				if(a + b + c == 0) {
					vector<int> v;
					v.push_back(a);
					v.push_back(b);
					v.push_back(c);
					res.push_back(v);
					while(start < n && num[start] == num[start + 1]) start++;
					start++;
					while(end > 0 && num[end - 1] == num[end]) end--;
					end--;
				}else if(a + b + c > 0) {
					while(end > 0 && num[end - 1] == num[end]) end--;
					end--;
				}else {
					while(start < n && num[start] == num[start + 1]) start++;
					start++;
				}
			}
		}
		return res;
 	} 
 };
