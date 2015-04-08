/**
 * Divide two integers without using multiplication, 
 * division and mod operator.
 *
 * If it is overflow, return MAX_INT.
 */

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
 	int divide(int divident, int divisor) {
 		
 	}
 }