/**
 * Given a non-negative number represented as an array of digits, 
 * plus one to the number.
 *
 * The digits are stored such that the most significant digit is 
 * at the head of the list.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int>::iterator digitEnd;
		vector<int> res;
		for (digitEnd = digits.end();digitEnd != digits.begin();digitEnd--) {
			if (*(digitEnd - 1) == 9) {
				res.insert(res.begin(), 0);
			}else {
				res.insert(res.begin(), (*(digitEnd - 1)) + 1);
				break;
			}
		}
		if (digitEnd == digits.begin())
			res.insert(res.begin(), 1);
		else
			res.insert(res.begin(), digits.begin(), digitEnd - 1);
		return res;
	}
};
