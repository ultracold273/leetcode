/**
 * LeetCode Q122 - Best Time to Buy and Sell Stock
 * Say you have an array for which the ith element is the price of a 
 * given stock on day i.
 *
 * Design an algorithm to find the maximum profit. 
 * You may complete as many transactions as you like (ie, buy one and 
 * sell one share of the stock multiple times). However, you may 
 * not engage in multiple transactions at the same time (ie, you must 
 * sell the stock before you buy again).
 *
 * If you were only permitted to complete at most one transaction 
 * (ie, buy one and sell one share of the stock), design an algorithm 
 * to find the maximum profit.
 *
 * Example 1:
 *
 * Input: [7, 1, 5, 3, 6, 4]
 * Output: 5
 *
 * max. profit = 5-1 + 6-3 = 7 
 *
 * Example 2:
 *
 * Input: [7, 6, 4, 3, 1]
 * Output: 0
 *
 * In this case, no transaction is done, i.e. max profit = 0.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) { 
        int maxProfit = 0; 
        int * seqMin = NULL;
        int i;
        if (prices.size() < 2) return 0;
        for(i = 0;i < prices.size() - 1;i++) {
            if (prices[i] <= prices[i + 1]) {
                if (seqMin == NULL) seqMin = &prices[i];
            }else {
                if (seqMin != NULL) {
                    maxProfit += prices[i] - *seqMin;
                    seqMin = NULL;
                }
            }
        }
        if (seqMin != NULL) {
            maxProfit += prices[i] - *seqMin;
            seqMin = NULL;
        }
        return maxProfit;
    }
};

int main() {
    Solution * sol = new Solution();
    int pi1[] = {7, 1, 5, 3, 6, 4};
    int pi2[] = {7, 6, 7, 4, 3, 1};
    int pi3[] = {1, 2};
    vector<int> p1(pi1, pi1 + sizeof(pi1) / sizeof(int));
    vector<int> p2(pi2, pi2 + sizeof(pi2) / sizeof(int));
    vector<int> p3(pi3, pi3 + sizeof(pi3) / sizeof(int));
    cout << sol->maxProfit(p1) << endl;
    cout << sol->maxProfit(p2) << endl;
    cout << sol->maxProfit(p3) << endl;
}
