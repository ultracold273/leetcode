/**
 * Given a set of distinct integers, nums, return all possible subsets.
 *
 * Note:
 *
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 *
 * For example,
 * If nums = [1,2,3], a solution is:
 *
 * [
 * 	[3],
 * 	[1],
 * 	[2],
 * 	[1,2,3],
 * 	[1,3],
 * 	[2,3],
 * 	[1,2],
 * 	[]
 * ]
 */

#include <iostream>
#include <vector>
using namespace std;

void printVectorArgs(vector<vector<int> >& in);
/* Reuse the combination */
class Solution {
public:
	vector<vector<int> > subsets(vector<int>& nums) {
		vector<vector<int> > res;
		if (nums.size() == 0) {
			res.push_back(vector<int>());
			return res;
		}else if (nums.size() == 1) {
			res.push_back(vector<int>(1, nums[0]));
			res.push_back(vector<int>());
		}else{
			vector<int> snums(nums.begin(), nums.end() - 1);
			res = subsets(snums);
			//for(vector<vector<int> >::iterator it = res.begin();it != res.end();++it) {
			int origSize = res.size();
			for(int i = 0;i < origSize;i++){
//				vector<int> copy(*it);
				vector<int> copy(res[i]);
				copy.push_back(nums[nums.size()-1]);
				res.push_back(copy);
			}
		}
		return res;
	}
};

void printVectorArgs(vector<vector<int> >& in) {
	cout << "\t[" << endl;
	for (int i = 0;i < (int) in.size();i++) {
		cout << "\t\t[";
		for(int j = 0;j < (int) in[i].size();j++) {
			cout << in[i][j] << ", ";
		}
		cout << "]," << endl;
	}
	cout << "\t]" << endl;
}

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	int intArgs[] = {1, 2, 3};
	vector<int> args(intArgs, intArgs + sizeof(intArgs) / sizeof(int) );
	vector<vector<int> > sbset;
	sbset = sol->subsets(args);
	cout << "\t[" << endl;
	printVectorArgs(sbset);
	return 0;
}
