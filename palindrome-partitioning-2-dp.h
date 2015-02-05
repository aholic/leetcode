//https://oj.leetcode.com/problems/palindrome-partitioning-ii/

class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        bool palTbl[len][len];
        for (int i = len-1; i>= 0; i--) {
            for (int j = i; j <= len-1; j++) {
                if (i == j) {
                    palTbl[i][j] = true;
                } else if (i + 1 == j) {
                    palTbl[i][j] = s[i] == s[j];
                } else {
                    palTbl[i][j] = s[i] == s[j] && palTbl[i+1][j-1];
                }
            }
        }

        int dp[len];
        for (int i = 0; i < len; i++) {
            if (palTbl[0][i]) {
                dp[i] = 0;
                continue;
            }
            dp[i] = i;
            for (int j = 0; j < i; j++) {
                if (!palTbl[j+1][i] || dp[j] + 1 >= dp[i]) continue;
                dp[i] = dp[j] + 1;
            }
        }

        return dp[len-1];
    }
};
