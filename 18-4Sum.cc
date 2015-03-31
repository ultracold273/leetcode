/**
 * Given an array S of n integers, are there elements a,b,c and d in S
 * such that a + b + c + d = target? Find all unique quadruplets in
 * the array which gives the sum of target.
 * Note:
 * Elements in a quadruplet (a, b, c, d) must be in non-descending order
 * The solution set must not contain duplicate quadruplets.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		int n = num.size();
		sort(num.begin(), num.end());
		vector<vector<int> > res;
		for (int i = 0;i < n;i++) {
			if (i > 0 && num[i-1] == num[i]) continue;
			int a = num[i];
			vector<int> v(num.begin() + i + 1, num.end());
			vector<vector<int> > vv = threeSum(v, target - a);
			if(vv.size() != 0) {
				for (int j = 0; j < vv.size(); ++j) {
					vv[j].insert(vv[j].begin(), a);
					res.push_back(vv[j]);
				}
			}
		}
		return res;
	}

	vector<vector<int> > threeSum(vector<int> &num, int target) {
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
				if(a + b + c == target) {
					vector<int> v;
					v.push_back(a);
					v.push_back(b);
					v.push_back(c);
					res.push_back(v);
					while(start < totalNum && num[start] == num[start + 1]) start++;
					start++;
					while(end > 0 && num[end - 1] == num[end]) end--;
					end--;
				}else if(a + b + c > target) {
					while(end > 0 && num[end - 1] == num[end]) end--;
					end--;
				}else {
					while(start < totalNum && num[start] == num[start + 1]) start++;
					start++;
				}
			}
		}
		return res;
	}
};

int main(int argc, char const *argv[])
{
	Solution * sol = new Solution();
	vector<int> a;
	//cout << sol->fourSum(a, 10) << endl;
	return 0;
}