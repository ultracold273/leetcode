/**
 * LeetCode Q179 - Largest Number
 * Given a list of non negative integers, arrange them such that they 
 * form the largest number.
 * 
 * Example 1:
 * Input: [10,2]
 * Output: "210"
 * 
 * Example 2:
 * Input: [3,30,34,5,9]
 * Output: "9534330"
 * Note: The result may be very large, so you need to return a string 
 * instead of an integer.
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// bool sortByFirstDigit(int x, int y) {
//     int x_digits, y_digits;
//     x_digits = y_digits = 0;
//     while (x > 9) {
//         x /= 10;
//         x_digits++;
//     }
//     while (y > 9) {
//         y /= 10;
//         y_digits++;
//     }
//     if (x > y) return true;
//     else if (x < y) return false;
//     else if (x_digits == 0) return true;
//     else if (y_digits == 0) return false;
//     else return sortByFirstDigit(x % int(pow(10, x_digits)), y % int(pow(10, y_digits)));
// }

bool sortByFirstDigit(int x, int y) {
    long long x_y = stoll(to_string(x) + to_string(y));
    long long y_x = stoll(to_string(y) + to_string(x));
    return x_y > y_x;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), sortByFirstDigit);
        string res;
        if (nums[0] == 0) return "0";
        for (auto num: nums) {
            res += to_string(num);
        }
        return res;
    }
};

int main() {
    Solution * sol = new Solution();
    vector<int> a; a.push_back(10);a.push_back(2);
    vector<int> b; b.push_back(3);
    b.push_back(30);
    b.push_back(34);
    b.push_back(5);
    b.push_back(9);
    cout << sol->largestNumber(a) << endl;
    cout << sol->largestNumber(b) << endl;
}