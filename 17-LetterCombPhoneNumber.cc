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
#include <map>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		map<char, string> digitsMap;
		digitsMap['2'] = "abc";
		digitsMap['3'] = "def";
		digitsMap['4'] = "ghi";
		digitsMap['5'] = "jkl";
		digitsMap['6'] = "mno";
		digitsMap['7'] = "pqrs";
		digitsMap['8'] = "tuv";
		digitsMap['9'] = "wxyz";
		vector<string> res;
		int n = digits.size();
		vector<int> iter(n, 0);
		int j = 0;
		while(j < n) {
			res.push_back(assemblyString(iter, digits, digitsMap));
			j = 0;
			while(j < n) {
				iter[j]++;
				if (iter[j] >= (int) digitsMap[digits[j]].size()) {
					iter[j] = 0;
					j++;
				}else{
					break;
				}
			}
		}
		return res;
	}

	string assemblyString(vector<int> & iter, string digits, map<char, string> & map) {
		int n = digits.size();
		string res;
		for(int i = 0;i < n;i++) {
			res.push_back(map[digits[i]][iter[i]]);
		}
		return res;
	}
};
