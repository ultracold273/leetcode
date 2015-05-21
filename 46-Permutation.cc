/**
 * Given a collection of numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
		vector<int> numsPer (nums);
		vector<vector<int> > res;
		sort(numsPer.begin(), numsPer.end());
		res.push_back(numsPer);
		while(nextPermutation(numsPer)) {
			res.push_back(nums);
		}
		return res;
    }

	bool nextPermutation(vector<int> &num) {
		int size = num.size();
		int last = size - 1;
		vector<int>::iterator it;
		while(last > 0) {
			if (num[last] > num[last - 1]) {
				// Find one discrepcy
				sort(num.end() - (size - last), num.end());
				// find the element that are larger than num[last - 1]
				it = upper_bound(num.end() - (size - last), num.end(), num[last - 1]);
				int pos = it - num.begin();
				int temp = num[last - 1];
				num[last - 1] = num[pos];
				num[pos] = temp;
				break;
			}
			last--;
		}
		if (last == 0) {
//			sort(num.begin(), num.end());
			return false;
		}
		return true;
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	int num1[] = {1, 3, 2};
	vector<int> v(num1, num1 + 3);
	sol->permute(v);
	for(int i = 0;i < (int) v.size();i++) {
		cout << v[i] << ", ";
	}
	cout << endl;
	int num2[] = {3, 2, 1};
	vector<int> v1(num2, num2 + 3);
	sol->permute(v1);
	for(int i = 0;i < (int) v1.size();i++) {
		cout << v1[i] << ", ";
	}
	cout << endl;

	int num3[] = {1, 1, 5};
	vector<int> v2(num3, num3 + 3);
	sol->permute(v2);
	for(int i = 0;i < (int) v2.size();i++) {
		cout << v2[i] << ", ";
	}
	cout << endl;

	int num4[] = {1, 1, 3, 4};
	vector<int> v3(num4, num4 + 4);
	for(int j = 0;j < 13;j++) {
		sol->permute(v3);
		for(int i = 0;i < (int) v3.size();i++) {
			cout << v3[i] << ", ";
		}
		cout << endl;
	}
	return 0;
}
