/**
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 *
 * 1. "123"
 * 2. "132"
 * 3. "213"
 * 4. "231"
 * 5. "312"
 * 6. "321"
 *
 * Given n and k, return the kth permutation sequence.
 *
 * Note: Given n will be between 1 and 9 inclusive.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int factorial(int n) {
		if (n == 0) return 1;
		int i = 1;
		int res = 1;
		while(i <= n) {
			res *= i;
			i++;
		}
		return res;
	}

	string getPermutation(int n, int k) {
		vector<int> unused; 
		for (int i = 1;i <= n;i++) unused.push_back(i);
		string res;
		int idx;
		k--;
		while(n > 0) {
			idx = k / factorial(n - 1);
			//cout << k << " " << n << " " << idx << endl;
			res.push_back('0' + unused[idx]);
			k = k % factorial(n - 1);
			n--;
			unused.erase(unused.begin() + idx);
		}
		return res;
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	int n = 3;
	for (int i = 1;i <= sol->factorial(n);i++)
		cout << sol->getPermutation(n, i) << endl;
	return 0;
}
