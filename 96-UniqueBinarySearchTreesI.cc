/**
 * LeetCode Q96 - Unique Binary Search Trees I
 * Given n, how many structurally unique BST's (binary search trees) 
 * that store values 1...n?
 *
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 *
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 */

/**
 * Catalan Numbers
 * Reasoning:
 * Any number in 1...n can be the root of the binary search tree
 * The number of BST of n nodes can be viewed as the sum of BSTs that
 * with every n as its root value:
 * BSTree(n) = BSTreeWithRoot(1) + ... + BSTreeWithRoot(n)
 *           = \sum_{i=1}^{n} BSTreeWithRoot(i)
 * The problem is reduce to find BSTreeWithRoot(i)
 * BST has an important properties:
 * [#] All node smaller than root must in its left tree
 * [#] All node larger than root must in its right tree
 * BSTreeWithRoot(i) is composed by two subBSTree:
 *     ^ Left BST: consist 1...i-1, BSTree(i - 1)
 *     ^ Right BST: consist i+1...n, BSTree(n - i)
 * So, BSTreeWithRoot(i) = BSTree(i - 1) * BSTree(n - i)
 * This problem can be solved in a recursive way (or by dynamic programming)
 * BSTree(n) = \sum_{i=1}^{n} BSTree(i - 1) * BSTree(n - i)
 */

#include <iostream>
using namespace std;

class Solution {
public:
	long calNumTrees(long *numBST, int n) {
		long res = 0;
		for (int i = 0;i <= n;i++) {
			res += numBST[i - 1] * numBST[n - i];
		}
		return res;
	}

	int numTrees(int n) {
		long numBST[100] = {0};
		if (n == 0) return 1;
		if (n == 1) return 1;
		numBST[0] = numBST[1] = 1;
		for(int i = 2;i <= n;i++) {
			numBST[i] = calNumTrees(numBST, i);
		}
		return numBST[n];
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	for (int i = 1;i < 11;i++) {
		cout << i << ":" << sol->numTrees(i) << endl;
	}
}
