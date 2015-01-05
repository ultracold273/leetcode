/**
 * LeetCode Question 9 - Palindrome Number
 * Determine whether an integer is a palindrome. Do this WITHOUT extra
 * space.
 * Hint: Negative numbers are not counted as palindrome number.
 */

#include <stdio.h>
#include <cmath>

//#define INT_MIN -2147483648

class Solution {
	private:
		int getFirstDigit(int x) {
			while(x > 9) {
				x /= 10;
			}
			return x;
		}
		int getNumberDigit(int x, int numPos) {
			int remain = x / pow(10, numPos);
			return remain % 10;
		}
	public:
		bool isPalindrome(int x) {
//			if (x == INT_MIN) return false;
			if (x < 0) return false;//x = -x;
			// Corner Case
			if (x < 10) return true;
			else if (x < 100) {
				if (x % 11 == 0) return true;
				else return false;
			}else{
//				int lastDigit = x % 10;
//				int firstDigit = getFirstDigit(x);
//				if (lastDigit != firstDigit) return false;
//				else {
//					return false;
//				}
				int totalDigit = log10(x);
				printf("ttlD:%d\n", totalDigit);
				int left,right;
				if (totalDigit % 2 == 0) {
					left = totalDigit / 2 + 1;
					right = totalDigit / 2 - 1;
				}else {
					left = totalDigit / 2 + 1;
					right = totalDigit / 2;
				}
				while(left <= totalDigit && right >= 0) {
					printf("left: %d, right: %d\n", getNumberDigit(x, left), getNumberDigit(x, right));
					if (getNumberDigit(x, left) != getNumberDigit(x, right))
						return false;
					left++;
					right--;
				}
				return true;
			}
		}
};

int main() {
	Solution * sol = new Solution();
	if(sol->isPalindrome(-2147447412))
	{
		printf("true");
	}
	else
	{
		printf("false");
	}
	return 0;
}
