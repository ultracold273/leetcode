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

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public: 
    int candy(vector<int>& ratings) { 
        vector<int> candies(ratings.size(), 0);
		// Sort ratings and find index
		vector<size_t> index(ratings.size());
		iota(index.begin(), index.end(), 0);
		sort(index.begin(), index.end(), [&ratings](size_t i1, size_t i2) {return ratings[i1] < ratings[i2];});
		// Fill the smallest
		for(auto idx : index) {
			int right = (idx < ratings.size() - 1)?candies[idx + 1]:0;
			int left = (idx > 0)? candies[idx - 1]:0;
			if (right == left && right == 0) {
				candies[idx] = 1;
			}else if (right > left) {
				// Tricky part
				if (ratings[idx] == ratings[idx + 1]) candies[idx] = left + 1;
				else candies[idx] = right + 1;
			}else {
				if (ratings[idx] == ratings[idx - 1]) candies[idx] = right + 1;
				else candies[idx] = left + 1;
			}
		}
		int totalCandies = 0;
		for (auto candy : candies) totalCandies += candy;
        return totalCandies;
    }
};

int main() {
	Solution * sol = new Solution();
	vector<int> ratings(2);
	ratings[0] = 2;ratings[1] = 2;
//	ratings[2] = 9;ratings[3] = 2;
	cout << sol->candy(ratings) << endl;
}
