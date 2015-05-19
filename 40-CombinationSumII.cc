/**
 * Given a set of candidate numbers (C) and a target number (T)
 * find all unique combinations in (C) where the candidate numbers sums
 * to T.
 *
 * Each number in C may only be used once in the combination.
 *
 * Note:
 * 	* All numbers (including target) will be positive integers.
 * 	* Elements in a combination (a1, a2, ..., ak) must be in 
 * 	  non-descending order.
 * 	* The Solution set must not contain duplicate combinations
 * 
 * For example, given candidate set 10, 1, 2, 7, 6, 1, 5 and target 8,
 * A solution set is:
 * [1, 7]
 * [1, 2, 5]
 * [2, 6]
 * [1, 1, 6]
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		return combinationSumRec(candidates.begin(), candidates.end(), target);
	}

	// The Candidate is sorted
	vector<vector<int> > combinationSumRec(vector<int>::iterator begin, vector<int>::iterator end, int target) {
		vector<vector<int> > resWithBegin;
		if (*begin == target) {
			vector<int> arrSingle;
			arrSingle.push_back(*begin);
			resWithBegin.push_back(arrSingle);
			return resWithBegin;
		}else if (*begin > target) {
			return resWithBegin;
		}else if (begin + 1 == end) {
			return resWithBegin;
		}
		vector<vector<int> > tmpA;
		tmpA = combinationSumRec(begin + 1, end, target - (*begin));
		for(vector<vector<int> >::iterator it = tmpA.begin();it != tmpA.end();it++) {
			it->insert(it->begin(), *begin);
		}
		resWithBegin.insert(resWithBegin.end(), tmpA.begin(), tmpA.end());
		// Find next different elem
		vector<int>::iterator it;
		for(it = begin + 1;it != end;it++) {
			if (*it != *begin) break;
		}
		if (it != end) {
			vector<vector<int> > resWithOutBegin = combinationSumRec(it, end, target); 
			resWithBegin.insert(resWithBegin.end(), resWithOutBegin.begin(), resWithOutBegin.end());
		}
		return resWithBegin;
	}
};

void printMatrix(vector<vector<int> > &matrix) {
	cout << '[' << endl;
	for (int i = 0;i < (int) matrix.size();i++) {
		cout << "\t[ ";
		for (int j = 0;j < (int) matrix[i].size();j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << ']' << endl;
	}
	cout << ']' << endl;
}

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	int input[7] = {10, 1, 2, 7, 6, 1, 5};
	vector<int> v (input, input + sizeof(input)/sizeof(int));
	vector<vector<int> > res = sol->combinationSum2(v, 8);
	printMatrix(res);
	return 0;
}
