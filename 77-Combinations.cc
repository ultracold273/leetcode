/**
 * Given two integers n and k, return all possible 
 * combinations of k numbers out of 1 ... n.
 *
 * For example,
 * If n = 4 and k = 2, a solution is:
 *
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > combine_rec(vector<int>& all, int size, int k) {
		vector<vector<int> > resVec(0);
		if (size < k) {
			return resVec;
		} else if (size == k) {
			return resVec.push_back(new vector<int>(all.begin(), all.begin() + size));
		} else {
			if (k == 1) {
			}else {
			}
		}
	}

	vector<vector<int> > combine(int n, int k) {
		vector<int> all(n);
		for (int i = 0;i < n;) {
			all[i] = i + 1;
		}
		return combine_rec(all, n, k);
	}
};
