/**
 * Given a collection of numbers that may contain duplicates, 
 * return all possible unique permutations.
 *
 * For example,
 * [1,1,2] have the following permutations:
 * [1,1,2], [1,2,1]  and [2,1,1]
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Modify a little from Problem 31. */
/* The same as Problem 46 */

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
		vector<int> numsPer (nums);
		vector<vector<int> > res;
		sort(numsPer.begin(), numsPer.end());
		res.push_back(numsPer);
		while(nextPermutation(numsPer)) {
			res.push_back(numsPer);
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

void printMatrix(vector<vector<int> > &nums) {
	cout << "[" << endl;
	for (int i = 0; i < nums.size(); ++i) {
		cout << "\t[ ";
		for (int j = 0; j < nums[i].size(); ++j) {
			cout << nums[i][j] << " ";
		}	
		cout << "]" << endl; 
	}
	cout << "]" << endl;
}

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	int num1[] = {1, 3, 2};
	vector<int> v(num1, num1 + 3);
	vector<vector<int> > vper = sol->permute(v);
	printMatrix(vper);

	int num2[] = {3, 2, 1};
	vector<int> v1(num2, num2 + 3);
	vector<vector<int> > v1per = sol->permute(v1);
	printMatrix(v1per);
	
	int num3[] = {1, 1, 5};
	vector<int> v2(num3, num3 + 3);
	vector<vector<int> > v2per = sol->permute(v2);
	printMatrix(v2per);
	
	int num4[] = {1, 1, 3, 4};
	vector<int> v3(num4, num4 + 4);
	vector<vector<int> > v3per = sol->permute(v3);
	printMatrix(v3per);
	return 0;
}
