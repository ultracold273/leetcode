/**
 * LeetCode Q134 - Gas Station
 * There are N gas stations along a circular route, where the amount of 
 * gas at station i is gas[i].
 *
 * You have a car with an unlimited gas tank and it costs cost[i] of gas 
 * to travel from station i to its next station (i+1). 
 * You begin the journey with an empty tank at one of the gas stations.
 *
 * Return the starting gas station's index if you can travel around the 
 * circuit once, otherwise return -1.
 *
 *  Note:
 *  The solution is guaranteed to be unique. 
 */

#include <vector>
using namespace std;

class Solution {
public: 
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int N = gas.size();
        int gasSum = 0;
        int costSum = 0;
        for(int i = 0;i < N;i++) gasSum += gas[i];
        for(int i = 0;i < N;i++) costSum += cost[i];
        if (gasSum < costSum) return -1;
        // Find largest cost
        int largestCost = 0;
        int largestCostIdx = 0;
        for (int i = 0;i < N;i++) {
            if (cost[i] > largestCost) {
                largestCost = cost[i];
                largestCostIdx = i;
            }
        }
        // Find the largest accumulation before largest cost
        // the start index is what we want. Why?
        int maxAccumulation = gas[largestCostIdx];
        int maxAccumulationStIdx = largestCostIdx;
        int accumulation = maxAccumulation;
        for (int i = 1;i < N;i++) {
            accumulation -= cost[(largestCostIdx - i + N) % N];
            accumulation += gas[(largestCostIdx - i + N) % N];
            if (accumulation > maxAccumulation) {
                maxAccumulation = accumulation;
                maxAccumulationStIdx = (largestCostIdx - i + N) % N;
            }
        }
        return maxAccumulationStIdx;
    }
};
