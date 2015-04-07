/**
 * Given a sorted array, 
 * remove the duplicates in place such that each element appear only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * 
 * For example,
 * Given input array A = [1,1,2],
 * Your function should return length = 2, and A is now [1,2].
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int count = 1;
        if (n <= 1) return n;
        int i = 1, j = 1;
        while(j < n) {
        	if (A[j - 1] == A[j]) {
        		j++;
        	}else {
        		A[i] = A[j];
        		i++;j++;
        		count++;
        	}
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
	Solution * sol = new Solution();
	int A[] = {1,1,2};
	int newLength = sol->removeDuplicates(A, 3);
	cout << newLength << endl;
	for (int i = 0; i < newLength; ++i)
	{
		cout << A[i] << ' ';
	}
	cout << endl;
	return 0;
}