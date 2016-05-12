/**
 * Given a collection of integers that might contain duplicates, nums, 
 * return all possible subsets.
 * 
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If nums = [1,2,2], a solution is:
 * 
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 */
 
 #include <iostream>
 #include <vector>
 using namespace std;
 
 class Solution {
 public:
     vector<vector<int> > subsetsWithDup(vector<int>& nums) {
         vector<vector<int> > res;
         vector<int> empty;
         if (nums.size() == 0) {
             res.push_back(empty);
             return res;
         }else if (nums.size() == 1) {
             res.push_back(empty);
             res.push_back(nums);
             return res;
         }else {
             vector<int> newNums(nums.begin() + 1, nums.end());
             vector<vector<int> > subI = subsetsWithDup(newNums);
             for (int i = 0;i < subI.size();i++) {
                 res.push_back(subI[i]);
                 if (nums[0] != nums[1]) {
                     subI[i].insert(subI[i].begin(), nums[0]);
                     res.push_back(subI[i]);
                 }else{
                     int cntDup = 0;
                     while(nums[++cntDup] == nums[0]);
                     if (subI[i][cntDup - 1] == nums[0]) {
                         subI[i].insert(subI[i].begin(), nums[0]);
                         res.push_back(subI[i]);
                     }
                 }
             }
             return res;
         }
     }
 };

int main(int argc, char * argv[]) {
    Solution *sol = new Solution();
    int numArr[] = {2, 2};
    vector<int> nums(numArr, numArr + sizeof(numArr) / sizeof(int));
    vector<vector<int> > res = sol->subsetsWithDup(nums);
    cout << '[' << endl;
    for(int i = 0;i < res.size();i++) {
        cout << '[';
        for (int j = 0;j < res[i].size();j++) {
            cout << res[i][j] << ' ';
        }
        cout << ']' << endl;
    }
    cout << ']' << endl;
}
