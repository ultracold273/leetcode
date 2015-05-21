/**
 * Given two numbers represented as strings,
 * return multiplication of the numbers as a string.
 *
 * Note: The numbers can be arbitrarily large and are non-negative.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/*
	string add(string num1, string num2) {
		string revSum;
		string * iterNum, * iteeNum;
		if (num1.size() > num2.size()) {
			iterNum = &num2;
			iteeNum = &num1;
		}else{
			iterNum = &num1;
			iteeNum = &num2;
		}
		int carry = 0;
		int tempSum = 0;
		int i;
		for (i = 0;i < (*iterNum).size();i++) {
			tempSum = (*iterNum)[i] - '0' + (*iteeNum)[i] - '0' + carry;
			revSum.push_back((tempSum % 10) + '0');
			carry = tempSum / 10;
		}

		for (;i < (*iteeNum).size();i++) {
			tempSum = (*iteeNum)[i] - '0' + carry;
			revSum.push_back((tempSum % 10) + '0');
			carry = tempSum / 10;
		}
		return revSum;
	}
	*/

	string multiply(string num1, string num2) {
		string prod;
		int num1Size = num1.size();
		int num2Size = num2.size();
		vector<int> numbers (num1Size + num2Size - 1, 0);
		for (int i = 0;i < num1Size;i++) {
			for (int j = 0;j < num2Size;j++) {
				numbers[i + j] += (num1[i] - '0') * (num2[j] - '0');
			}
		}
		int carry = 0;
		for(vector<int>::reverse_iterator it = numbers.rbegin();it != numbers.rend();it++) {
//			cout << *it << endl;
			int number = *it + carry;
			prod.push_back((number % 10) + '0');
			carry = number / 10;
		}
		if (carry != 0) {
			prod.push_back(carry + '0');
		}

		//reverse(prod.begin(), prod.end());
		int edPos = prod.size() - 1;
		while(prod[edPos] == '0' && edPos > 0) edPos--;
		string prodNew (prod, 0, edPos + 1);
		/*
		while(stPos < edPos) {
			char temp = prod[stPos];
			prod[stPos] = prod[edPos];
			prod[edPos] = temp;
			stPos++;
			edPos--;
		}
		*/
		reverse(prodNew.begin(), prodNew.end());
		return prodNew;
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	cout << sol->multiply("1789", "0") << endl;
	cout << "real answer: " << 1789 * 0 << endl;
	return 0;
}
