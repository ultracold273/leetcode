/**
 *  Given a digit string, return all possible letter
 *  combinations that the number could represent.
 *  Input: digit string "23"
 *  Output: ["ad", "ae", "af", "bd", "be", "bf", "cd",
 *  "ce", "cf"]
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		map<string, string> digitsMap;
		digitsMap["2"] = "abc";
		digitsMap["3"] = "def";
		digitsMap["4"] = "ghi";
		digitsMap["5"] = "jkl";
		digitsMap["6"] = "mno";
		digitsMap["7"] = "pqrs";
		digitsMap["8"] = "tuv";
		digitsMap["9"] = "wxyz";
		int n = digits.size();
	}
};
