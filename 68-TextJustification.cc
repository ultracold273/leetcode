/**
 * Given an array of words and a length L, format the text such that 
 * each line has exactly L characters and is fully (left and right) 
 * justified.
 *
 * You should pack your words in a greedy approach; 
 * that is, pack as many words as you can in each line. 
 * Pad extra spaces ' ' when necessary so that each line has exactly 
 * L characters.
 *
 * Extra spaces between words should be distributed as evenly as 
 * possible. 
 * If the number of spaces on a line do not divide evenly between words, 
 * the empty slots on the left will be assigned more spaces than the 
 * slots on the right.
 *
 * For the last line of text, it should be left justified and no 
 * extra space is inserted between words.
 *
 * For example,
 * words: ["This", "is", "an", "example", "of", "text", "justification."]
 * L: 16.
 *
 * Return the formatted lines as:
 *
 * [
 * 	"This    is    an",
 *  "example  of text",
 *  "justification.  "
 * ]
 *
 * Note: Each word is guaranteed not to exceed L in length. 
 *
 * Corner Cases:
 *
 * A line other than the last line might contain only one word. 
 * What should you do in this case?
 * In this case, that line should be left-justified.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string justify(vector<string>& words, int start, int end, int width) {
		string res;
		int totalSize = 0;
		for(int i = start;i <= end;i++) {
			totalSize += words[i].size();
		}
		int spaceInserted = width - totalSize;
		int spaceFormer, spaceLatter;
		int splitPoint;
		if (end == start) {
			spaceFormer = spaceLatter = spaceInserted;
			splitPoint = -2;
		}else {
			spaceFormer = spaceInserted / (end - start);
			if (spaceInserted % (end - start)) {
				spaceLatter = spaceFormer;
				spaceFormer++;
				splitPoint = (spaceInserted - spaceLatter * (end - start))/(spaceFormer - spaceLatter) + start;
			}else {
				spaceLatter = spaceFormer;
				splitPoint = -1;
			}
		}
		if (splitPoint == -2) {
			res += words[start];
			res += string(spaceFormer, ' ');
		}else{
			for (int i = start;i < end;i++) {
				if (splitPoint == -1) {
					res += words[i];
					res += string(spaceFormer, ' ');
				}else {
					res += words[i];
					res += string((i >= splitPoint)?spaceLatter:spaceFormer, ' ');
				}
			}
			res += words[end];
		}
//		cout << start << " " << end << " " << spaceInserted << " ";
		return res;
	}

	string justifyLastLine(vector<string>& words, int start, int end, int width) {
		string res;
		int curSpaceCount = 0;
		for (int i = start;i < end;i++) {
			res += words[i] + ' ';
			curSpaceCount += words[i].size() + 1;
		}
		res += words[end];
		curSpaceCount += words[end].size();
		if (curSpaceCount < width) {
			res += string(width - curSpaceCount, ' ');
		}
		return res;
	}

	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		int start = 0;
		int end;
		int curSize = 0;
		vector<string> res;
		for (end = 0;end < (int) words.size();end++) {
			curSize += words[end].size() + 1;
			if (curSize > maxWidth + 1) {
				res.push_back(justify(words, start, end - 1, maxWidth));
				curSize = words[end].size() + 1;
				start = end;
			}else if (curSize == maxWidth + 1) {
				res.push_back(justify(words, start, end, maxWidth));
				curSize = 0;
				start = end + 1;
			}
		}
		if (start != words.size()) {
			res.push_back(justifyLastLine(words, start, end - 1, maxWidth));
		}
		return res;
	}
};

int main(int argc, char * argv[]) {
	Solution * sol = new Solution();
	vector<string> words;
	words.push_back("This");
	words.push_back("is");
	words.push_back("an");
	words.push_back("example");
	words.push_back("of");
	words.push_back("text");
	words.push_back("justification.");
//	words.push_back("a");
//	cout << sol->justify(words, 0, 0, 7) << "|" << endl;
//	cout << sol->justify(words, 1, 1, 7) << "|" << endl;
//	cout << sol->justify(words, 1, 2, 7) << "|" << endl;
//	cout << sol->justify(words, 1, 3, 10) << "|" << endl;
//	cout << sol->justify(words, 1, 3, 11) << "|" << endl;
	vector<string> res = sol->fullJustify(words, 14);
	for(int i = 0;i < (int)res.size();i++) {
		cout << "|" << res[i] << "|" << endl;
	}
	vector<string> words1;
	words1.push_back("a");
	words1.push_back("b");
	words1.push_back("c");
	words1.push_back("d");
	words1.push_back("e");
	res = sol->fullJustify(words1, 1);
	for(int i = 0;i < (int)res.size();i++) {
		cout << "|" << res[i] << "|" << endl;
	}
	return 0;
}
