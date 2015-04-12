/**
 * Divide two integers without using multiplication, 
 * division and mod operator.
 *
 * If it is overflow, return MAX_INT.
 */

 #define INT_MAX 2147483647
 #define INT_MIN (-INT_MAX - 1)
 #include <iostream>
 using namespace std;

 class Solution {
 public:
 	// It seems that we cannot use minus
 	/*
 	int divide(int divident, int divisor) {
 		if (divisor == 0) return MAX_INT;
 		if (divident == 0) return 0;
 		int sign = ((divident > 0 && divisor > 0) || (divident < 0 && divisor < 0))?1:-1;
 		int abs_divident = abs(divident);
 		int abs_divisor = abs(divisor);
 		int quotient = 0;
 		while(abs_divisor < abs_divident) {
 			quotient++;
 			abs_divident -= abs_divisor;
 		}
 		return (sign == 1)?quotient:-quotient;
 	}
 	*/
 	int divide(int dividend, int divisor) {
 		unsigned int res = 0;
 		if (divisor == 0) return INT_MAX;
 		if (divisor == 1) return dividend;
 		int sign = ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))?1:-1;
 		cout << "sign " << sign << endl;
 		unsigned int abs_divisor = (divisor > 0)?divisor:-divisor;
 		unsigned int abs_dividend = (dividend > 0)?dividend:-dividend;

 		int i = 0;
 		//cout << abs_divisor << " " << abs_dividend << endl;
 		while(abs_dividend > (abs_divisor << i)) i++;
 		if (abs_dividend != (abs_divisor << i)) i--;
 		//cout << i << endl;

 		
 		while(abs_dividend >= abs_divisor) {
 		//	cout << "abs_dividend: " << abs_dividend << endl;
 			if (abs_dividend >= (abs_divisor << i)) {
 				res += (1 << i);
 		//		cout << "res: " << res << endl;
 				abs_dividend -= (abs_divisor << i);
 			}else{
 				i--;
 			}
 		}

 		if (res > INT_MAX && sign == 1) return INT_MAX;

 		return (sign == 1)?res:-res;
 	}
 };

int main(int argc, char const *argv[])
{
	Solution *sol = new Solution();
	cout << sol->divide(10, 3) << endl;
	cout << sol->divide(10, 10) << endl;
	cout << sol->divide(10, 20) << endl;
	cout << sol->divide(2147483647, 2) << endl;
	cout << sol->divide(-2147483648, -1) << endl;
	return 0;
}