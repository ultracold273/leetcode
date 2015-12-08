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
	vector<vector<int> > combine_rec(int n, int k) {
		vector<vector<int> > res;
		if (n < 1 || n < k) {
			res.push_back(vector<int>(0));
		}else if (n == 1) {
			res.push_back(vector<int>(1, 1));
		}
		else if (k == 1) {
			for (int i = 1;i <= n;i++) {
				res.push_back(vector<int>(1, i));
			}
		}else {
			vector<vector<int> > part1 = combine_rec(n - 1, k);
			vector<vector<int> > part2 = combine_rec(n - 1, k - 1);
			for(vector<vector<int> >::iterator it = part2.begin(); it != part2.end(); ++it) {
				it->push_back(n);
			}

			for(vector<vector<int> >::iterator it = part1.begin(); it != part1.end(); ++it) {
				if (it->size() != 0)
					res.push_back(*it);
			}
			for(vector<vector<int> >::iterator it = part2.begin(); it != part2.end(); ++it) {
				res.push_back(*it);
			}
		}
		return res;
	}

	vector<vector<int> > combine(int n, int k) {
		if (n < 1 || n < k || k < 1) return vector<vector<int> >(0);
		return combine_rec(n, k);
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	vector<vector<int> > combinator;
	combinator = sol->combine(4, 0);
	cout << "\t[" << endl;
	for (int i = 0;i < (int) combinator.size();i++) {
		cout << "\t\t[";
		for(int j = 0;j < (int) combinator[i].size();j++) {
			cout << combinator[i][j] << ", ";
		}
		cout << "]," << endl;
	}
	cout << "\t]" << endl;
}

