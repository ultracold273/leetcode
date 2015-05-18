class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";
        if (n == 1) return "1";
        if (n > 1) {
            string strCount = countAndSay(n - 1);
            int strSize = strCount.size();
            int count;
            char curDigit;
            string strSay;
            for (int i = 0; i < strSize;i++) {
                if (i == 0) {
                    count = 1;
                    curDigit = strCount[i];
                }else{
                    if (strCount[i] == curDigit) {
                        count++;
                    }else{
                        strSay.push_back('0' + count);
                        strSay.push_back(curDigit);
                        count = 1;
                        curDigit = strCount[i];
                    }
                }
            }
            strSay.push_back('0' + count);
            strSay.push_back(curDigit);
            return strSay;
        }
        
    }
};