/**
 * LeetCode Q166 - Fraction to Recurring Decimal
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 *
 * If the fractional part is repeating, enclose the repeating part in parentheses.
 * 
 * Example 1:
 * Input: numerator = 1, denominator = 2
 * Output: "0.5"
 * 
 * Example 2:
 * Input: numerator = 2, denominator = 1
 * Output: "2"
 * 
 * Example 3:
 * Input: numerator = 2, denominator = 3
 * Output: "0.(6)"
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    string buildStringFromDecimalCollection(vector<long long> &decimals, int recur_st) {
        string res;
        if (recur_st < 0) {
            // no recurring numbers
            for (auto decimal: decimals) {
                res += to_string(decimal);
            }
        } else {
            for (int i = 0;i < decimals.size();i++) {
                if (i == recur_st) res += "(";
                res += to_string(decimals[i]);
            }
            res += ")";
        }
        return res;
    }

    string fractionToDecimal(int numerator, int denominator) {
        long long num = numerator;
        long long denom = denominator;
        num = abs(num);
        denom = abs(denom);
        long long integer, residue;
        bool negative_flag = ((numerator < 0) && (denominator > 0)) || ((numerator > 0) && (denominator < 0));
        integer = num / denom;
        string integer_str = to_string(integer);
        if (negative_flag) integer_str = "-" + integer_str;
        string decimal_str;
        if (num % denom == 0) return integer_str;
        else {
            residue = num % denom;
            map<long long, int> residue_collection;
            vector<long long> decimal_collection;
            int pos = 0;
            while (residue != 0 && residue_collection.find(residue) == residue_collection.end()) {
                residue_collection[residue] = pos++;
                decimal_collection.push_back((residue * 10) / denom);
                // decimal_str += to_string((residue * 10) / denom);
                residue = (residue * 10) % denom;
            }
            if (residue == 0) {
                decimal_str = buildStringFromDecimalCollection(decimal_collection, -1);
            }
            else {
                decimal_str = buildStringFromDecimalCollection(decimal_collection, residue_collection[residue]);
            }
            return integer_str + "." + decimal_str;
        }
    }
};

int main() {
    Solution * sol = new Solution();
    cout << "1/2 = " << sol->fractionToDecimal(1, 2) << endl;
    cout << "2/1 = " << sol->fractionToDecimal(2, 1) << endl;
    cout << "2/3 = " << sol->fractionToDecimal(2, 3) << endl;
    cout << "1/7 = " << sol->fractionToDecimal(1, 7) << endl;
    cout << "1/6 = " << sol->fractionToDecimal(1, 6) << endl;
    cout << "-50/8 = " << sol->fractionToDecimal(-50, 8) << endl;
    cout << sol->fractionToDecimal(-2147483648, 1) << endl;
    cout << sol->fractionToDecimal(1, -2147483648) << endl;
}