/**
 * LeetCode Q135 - Candy
 * There are N children standing in a line. 
 * Each child is assigned a rating value.
 *
 * You are giving candies to these children subjected to the following 
 * requirements:
 *
 *   Each child must have at least one candy.
 *   Children with a higher rating get more candies than their neighbors.
 *
 *   What is the minimum candies you must give? 
 */

#include <vector>
using namespace std;

class Solution {
public: 
    int candy(vector<int>& ratings) { 
        vector<int> candy(ratings.size(), 0);
        return sum(candy);
    }
};
