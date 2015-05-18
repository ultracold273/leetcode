/**
 * Given a set of candidate numbers (C) and a target number (T)
 * find all unique combinations in (C) where the candidate numbers sums
 * to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * 	* All numbers (including target) will be positive integers.
 * 	* Elements in a combination (a1, a2, ..., ak) must be in 
 * 	  non-descending order.
 * 	* The Solution set must not contain duplicate combinations
 * 
 * For example, given candidate set 2, 3, 6, 7 and target 7,
 * A solution set is:
 * [7]
 * [2, 2, 3]
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
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
			if (target % (*begin) == 0) {
				vector<int> arrMultiple (target / (*begin), *begin);
				resWithBegin.push_back(arrMultiple);
			}
			return resWithBegin;
		}else{
			int i = 1;
			while (*begin * i <= target) {
				vector<vector<int> > tmpA;
			    if (*begin * i < target) {
				    tmpA = combinationSumRec(begin + 1, end, target - i * (*begin));
				    for(vector<vector<int> >::iterator it = tmpA.begin();it != tmpA.end();it++) {
					    it->insert(it->begin(), i, *begin);
				    }
			    }else{
			        vector<int> a (i, *begin);
			        tmpA.push_back(a);
			    }
				resWithBegin.insert(resWithBegin.end(), tmpA.begin(), tmpA.end());
				i++;
			}
		}
		vector<vector<int> > resWithOutBegin = combinationSumRec(begin + 1, end, target); 
		resWithBegin.insert(resWithBegin.end(), resWithOutBegin.begin(), resWithOutBegin.end());
		return resWithBegin;
	}
};

void printMatrix(vector<vector<int> > &matrix) {
	cout << '[' << endl;
	for (int i = 0;i < matrix.size();i++) {
		cout << "\t[ ";
		for (int j = 0;j < matrix[i].size();j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << ']' << endl;
	}
	cout << ']' << endl;
}

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	int input[4] = {2, 3, 6, 7};
	vector<int> v (input, input + sizeof(input)/sizeof(int));
	vector<vector<int> > res = sol->combinationSum(v, 7);
	printMatrix(res);
	return 0;
}
