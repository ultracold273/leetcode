/**
 *  Given two binary strings, return their sum (also a binary string).
 *
 *  For example,
 *  a = "11"
 *  b = "1"
 *  Return "100". 
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		// Ensure a is longer
		if (a.size() < b.size()) {
			string temp;
			temp = b;
			b = a;
			a = temp;
		}
		string res;
		int carry = 0;
		int sum;
		int asize = a.size();
		int bsize = b.size();
		for (int i = 0;i < (int) a.size();i++) {
			sum = carry + a[asize - i - 1] - '0';
			if (i < (int) b.size())
				sum += b[bsize - i - 1] - '0';
			if (sum % 2) {
				res.insert(res.begin(), '1');
			}else{
				res.insert(res.begin(), '0');
			}
			if (sum / 2) {
				carry = 1;
			}else {
				carry = 0;
			}
		}
		if (carry == 1)
			res.insert(res.begin(), '1');

		return res;
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	cout << sol->addBinary("11", "1") << " 100" << endl;
	cout << sol->addBinary("1", "111") << " 1000" << endl;
	cout << sol->addBinary("0", "10") << " 10" << endl;
}
