/**
 * LeetCode Q123 - Best Time to Buy and Sell Stock III
 *
 * Say you have an array for which the ith element is the price of a 
 * given stock on day i.
 *
 * Design an algorithm to find the maximum profit. 
 * You may complete at most two transactions.
 *
 * Note:
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
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxTwo(vector<int>& maxs) {
        sort(maxs.begin(), maxs.end(), greater<int>());
        if (maxs.size() == 0) return 0;
        else if (maxs.size() == 1) return maxs[0];
        else return maxs[0] + maxs[1];
    }

    int maxProfit_old(vector<int>& prices) { 
        vector<int> maxProfits; 
        int * seqMin = NULL;
        int i;
        if (prices.size() < 2) return 0;
        for(i = 0;i < (int) prices.size() - 1;i++) {
            if (prices[i] <= prices[i + 1]) {
                if (seqMin == NULL) seqMin = &prices[i];
            }else {
                if (seqMin != NULL) {
                    maxProfits.push_back(prices[i] - *seqMin);
                    seqMin = NULL;
                }
            }
        }
        if (seqMin != NULL) {
            maxProfits.push_back(prices[i] - *seqMin);
            seqMin = NULL;
        }
        return maxTwo(maxProfits);
    }

    /* We shall consider the strategy that how they chooses */
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
