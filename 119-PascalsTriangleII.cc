/**
 * LeetCode 119 - Pascal's Triangle II
 *
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 * For example, given k = 3,
 * Return [1,3,3,1].
 *
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> oddRow;
        vector<int> evenRow;
        evenRow.push_back(1);
        oddRow.push_back(1);
        oddRow.push_back(1);
        for(int i = 1;i < rowIndex;i++) {
            int j;
            if (i % 2 == 1) {
                for(j = 0;j < oddRow.size() - 2;j++) {
                    evenRow[j + 1] = oddRow[j] + oddRow[j + 1];
                }
                evenRow.push_back(oddRow[j] + oddRow[j+1]);
                evenRow.push_back(1);
            }else {
                for(j = 0;j < evenRow.size() - 2;j++) {
                    oddRow[j + 1] = evenRow[j] + evenRow[j + 1];
                }
                oddRow.push_back(evenRow[j] + evenRow[j+1]);
                oddRow.push_back(1);
            }
        }
        return (rowIndex % 2 == 1)?oddRow:evenRow;
    }
};

int main() {
    Solution * sol = new Solution();
    vector<int> res = sol->getRow(3);
    cout << '[';
    for (int i = 0;i < res.size();i++){
        cout << res[i] << " ";
    }
    cout << ']';
    return 0;
}
