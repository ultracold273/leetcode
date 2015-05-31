/**
 * Implement pow(x, n). 
 */

#include <iostream>
using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		double power = 1.0;
		bool neg = (n < 0);
		if (neg) n = -n;
		int bt = 0;
		// bt < 32 tailor for overflow condition
		while(n > (1 << bt) && bt < 32) bt++;
//		cout << "bt = " << bt << endl;
		while (bt >= 0) {
			power *= power;
			if ((n & (1 << bt)) != 0) {
				power *= x;
			}
			bt--;
		}
		return (neg)?1.0/power:power;
	}
};

int main(int argc, char * argv[]){
	Solution * sol = new Solution();
	cout << sol->myPow(2.0, 0) << endl;
	cout << sol->myPow(2.0, 1) << endl;
	cout << sol->myPow(2.0, 2) << endl;
	cout << sol->myPow(2.0, 4) << endl;
	cout << sol->myPow(2.0, 9) << endl;
	cout << sol->myPow(0.00001, 2147483647) << endl;
}
