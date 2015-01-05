/**
 * LeetCode Question 2
 * Median of Two Sorted Arrays
 * Description:
 * There are two sorted arrays A and B of size m and n respectively.
 * Find the median of the two sorted arrays. The overall runtime
 * should be O(log (m+n)).
 * Date: 2014-12-17
 */

#include <stdio.h>

class Solution {
	private:
		double getMedian(int A[], int n) {
			if (n % 2 == 0) {
				return 0.5 * (A[n/2] + A[n/2 -1]);
			}else{
				return A[n/2];
			}
		}
		double getMedianFromArrayOne(int a, int B[], int n) {
			if (n == 1) {
				return 0.5 * (a + B[0]);
			}else if (n % 2 == 0) {
				if (a <= B[n/2-1])
					return B[n/2-1];
				else if (a >= B[n/2]) {
					return B[n/2];
				}else {
					return a;
				}
			}else{
				if (a <= B[n/2-1]) {
					return 0.5 * (B[n/2-1] + B[n/2]);
				}else if (a <= B[n/2 + 1]) {
					return 0.5 * (a + B[n/2]);
				}else{
					return 0.5 * (B[n/2] + B[n/2+1]);
				}
			}
		}
		double getMedianFromArrayTwo(int a_l, int a_h, int B[], int n) {
			if (n % 2 == 0) {
				if (a_h <= B[n/2] && a_l <= B[n/2-1]) {
					if (n > 2 && a_h < B[n/2-2]) {
						return 0.5 * (B[n/2-2] + B[n/2-1]);
					}else
						return 0.5 * (a_h + B[n/2-1]);
				}else if (a_l <= B[n/2 -1] && a_h >= B[n/2] ) {
					return getMedian(B, n);
				}else if (a_l > B[n/2 - 1] && a_h <= B[n/2]) {
					return 0.5 * (a_l + a_h);
				}else {
					if (n > 2 && a_l > B[n/2+1]) {
						return 0.5 * (B[n/2] + B[n/2+1]);
					}else
						return 0.5 * (a_l + B[n/2]);
				}
			}else {
				double medianB = getMedian(B,n);
				double medianA = 0.5 * (a_l + a_h);
				if (medianA == medianB)
					return medianA;
				else if (medianA < medianB) {
					return getMedianFromArrayOne(a_h, B, n - 1);
				}else{
					return getMedianFromArrayOne(a_l, &B[1], n - 1);
				}
			}
			return 0.0;
		}
	public:
		double findMedianSortedArrays(int A[], int m, int B[], int n) {
			if (m == 0 && n == 0) return 0.0;
			if (m == 0) {
				return getMedian(B, n);
			}
			if (n == 0) {
				return getMedian(A, m);
			}
			if (m == 1) {
				return getMedianFromArrayOne(A[0], B, n);
			}
			if (n == 1) {
				return getMedianFromArrayOne(B[0], A, m);
			}
			if (m == 2) {
				return getMedianFromArrayTwo(A[0], A[1], B, n);
			}
			if (n == 2) {
				return getMedianFromArrayTwo(B[0], B[1], A, m);
			}
			double aMedian, bMedian;
			aMedian = getMedian(A, m);
			bMedian = getMedian(B, n);
			if (aMedian == bMedian) {
				return aMedian;
			}else if (aMedian < bMedian) {
				if (m > n) {
					return findMedianSortedArrays(&A[n/2], m - n/2, B, (n+1)/2);
				}else {
					return findMedianSortedArrays(&A[m/2], (m+1)/2, B, n - m/2);
				}
			}else {
				if (m > n) {
					return findMedianSortedArrays(A, m - n/2, &B[n/2], (n+1)/2);
				}else {
					return findMedianSortedArrays(A, (m+1)/2, &B[m/2], n - m/2);
				}
			}
		}
};


int main(void) {
	Solution * a = new Solution();
	int A[3] = {3, 4, 5};
	int m = sizeof(A)/sizeof(A[0]);
	int B[3] = {1, 2, 6};
	int n = sizeof(A)/sizeof(A[0]);
	double med = a->findMedianSortedArrays(A, m, B, n);
	printf("Median: %lf\n", med);
	return 0;
}
