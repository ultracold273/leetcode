/**
 * LeetCode Question 8 - String to Integer (atoi)
 * Implement atoi to covert a string to an integer
 *
 */

#define INT_MAX 2147483647
#define INT_MIN -2147483648

#include <stdio.h>

class Solution {
	public:
		int atoi(const char *str) {
			bool isValid = false;
			int idx = 0;
			while(str[idx] != '\0') {
				if (str[idx] != ' ') {
					if (str[idx] == '+' || str[idx] == '-' || (str[idx] >= '0' && str[idx] <= '9')) {
						isValid = true;
					}
					break;
				}
				idx++;
			}
			if (isValid) {
				int pnFlag = 1;
				int result = 0;
				int prev;
				if(str[idx] == '-') {
					pnFlag = -1;
					idx++;
				}
				else if (str[idx] == '+') {
					idx++;
				}
				while(str[idx] >= '0' && str[idx] <= '9') {
					prev = result;
					result = result * 10 + str[idx] - '0';
					// Overflow Detection
					if (result / 10 != prev) {
						if (pnFlag == 1) return INT_MAX;
						if (pnFlag == -1) return INT_MIN;
					}
					idx++;
				}
				return pnFlag * result;
			}
			return 0;
		}
};

int main() {
	Solution * sol = new Solution();
	printf("%d\n", sol->atoi("010"));
	return 0;
}
