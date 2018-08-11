/**
 * LeetCode Q273 - Integer to English Words
 * Convert a non-negative integer to its english words representation. 
 * Given input is guaranteed to be less than 2^31 - 1.
 *
 * Example 1:
 * 
 * Input: 123
 * Output: "One Hundred Twenty Three"
 * Example 2:
 * 
 * Input: 12345
 * Output: "Twelve Thousand Three Hundred Forty Five"
 * Example 3:
 * 
 * Input: 1234567
 * Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 * Example 4:
 * 
 * Input: 1234567891
 * Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven 
 * Thousand Eight Hundred Ninety One"
 */

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string numberToBasicWords(int num) {
        // num is smaller than 1000
        string oneDigits[9] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string tens[9] = {"Ten", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string special[9] = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string res;
        if (num > 99) {
            res += oneDigits[(num / 100) - 1] + " Hundred ";
            num = num % 100;
        }
        if (num > 10 && num < 20) {
            res += special[num - 11];
            res += " ";
            return res;
        }
        if (num > 9) {
            res += tens[(num / 10) - 1];
            res += " ";
            num = num % 10;
        }
        if (num != 0) {
            res += oneDigits[num - 1];
            res += " ";
        }
        return res;
    }
    
    string numberToWords(int num) {
        string quant[] = {"", "Thousand", "Million", "Billion", "Trillon"};
        string res;
        int quant_cnt = 0;
        if (num == 0) return "Zero";
        do {
            int residue = num % 1000;
            if (residue != 0) {
                string basic_words = numberToBasicWords(residue);
                if (quant_cnt == 0) {
                    res = basic_words;
                }else{
                    res = basic_words + quant[quant_cnt] + " " + res;
                }
            }
            quant_cnt++;
            num = num / 1000;
        } while (num > 0);
        return res.substr(0, res.length()-1);
    }
};

int main() {
    Solution * sol = new Solution();
    for (int i = 0;i < 1000;i++) {
        cout << i << " " << sol->numberToBasicWords(i) << endl;
    }
    cout << "123" << " " << sol->numberToWords(123) << "x" << endl;
    cout << "12345" << " " << sol->numberToWords(12345) << "x" << endl;
    cout << "1234567" << " " << sol->numberToWords(1234567) << "x" << endl;
    cout << "1234567891" << " " << sol->numberToWords(1234567891) << "x" << endl;
    cout << "1230000091" << " " << sol->numberToWords(1230000091) << "x" << endl;
}