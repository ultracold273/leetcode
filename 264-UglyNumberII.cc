/**
 * LeetCode Q264 - Ugly Number II
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
 * 
 * Example:
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly  * numbers.
 * Note:  
 * 
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long> uglyNumber;
        if (n == 1) return 1;
        uglyNumber.push_back(1);
        int dp_st = 0;
        for(int i = 1;i < n;i++) {
            if (uglyNumber[dp_st] * 5 < uglyNumber[i-1]) dp_st++;
            long min = uglyNumber[i-1] * 5;
            for(int j = dp_st;j < i;j++) {
                long a = uglyNumber[j] * 2;
                long b = uglyNumber[j] * 3;
                long c = uglyNumber[j] * 5;
                if (a > uglyNumber[i-1] && a < min) min = a;
                if (b > uglyNumber[i-1] && b < min) min = b;
                if (c > uglyNumber[i-1] && c < min) min = c;
            }
            uglyNumber.push_back(min);
        }
        return uglyNumber[n-1];
    }
};
