/**
 * Leetcode 31 - Next Permutation
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * If such arrangements is not possible, it must rearrange it as
 * the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and
 * its corresponding ouputs are in the right-hand column.
 * 1,2,3 -> 1,3,2
 * 3,2,1 -> 1,2,3
 * 1,1,5 -> 1,5,1
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		void nextPermutation(vector<int> &num) {
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
				sort(num.begin(), num.end());
			}
			return;
	
		}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	int num1[] = {1, 3, 2};
	vector<int> v(num1, num1 + 3);
	sol->nextPermutation(v);
	for(int i = 0;i < (int) v.size();i++) {
		cout << v[i] << ", ";
	}
	cout << endl;
	int num2[] = {3, 2, 1};
	vector<int> v1(num2, num2 + 3);
	sol->nextPermutation(v1);
	for(int i = 0;i < (int) v1.size();i++) {
		cout << v1[i] << ", ";
	}
	cout << endl;

	int num3[] = {1, 1, 5};
	vector<int> v2(num3, num3 + 3);
	sol->nextPermutation(v2);
	for(int i = 0;i < (int) v2.size();i++) {
		cout << v2[i] << ", ";
	}
	cout << endl;

	int num4[] = {1, 1, 3, 4};
	vector<int> v3(num4, num4 + 4);
	for(int j = 0;j < 13;j++) {
		sol->nextPermutation(v3);
		for(int i = 0;i < (int) v3.size();i++) {
			cout << v3[i] << ", ";
		}
		cout << endl;
	}
	return 0;
}
