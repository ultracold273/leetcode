/**
 * Divide two integers without using multiplication, 
 * division and mod operator.
 *
 * If it is overflow, return MAX_INT. 
 */

#include <iostream>
using namespace std;
#define MAX_INT 0x7FFFFFFF

class Solution {
public:
	int divide(int dividend, int divisor) {
		unsigned int res = 0;
		if (divisor == 0) return MAX_INT;
		if (divisor == 1) return dividend;
		int sign = ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))?1:-1;
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
				//cout << "res: " << res << endl;
				abs_dividend -= (abs_divisor << i);
			}else{
				i--;
			}
		}
		if (res > MAX_INT && sign == 1) return MAX_INT;
		return (sign == 1)?res:-res;
	}
};
