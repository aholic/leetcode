//https://oj.leetcode.com/problems/distinct-subsequences/

class Solution {
public:
    int numDistinct(string s1, string s2) {
        int dp[s2.length()][s1.length()];
        for (int i = 0; i < s2.length(); i++) {
            for (int j = 0; j < s1.length(); j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = s2[i] == s1[j] ? 1 : 0;
                } else if (i == 0 && j != 0) {
                    dp[i][j] = dp[i][j-1] + (s2[i] == s1[j] ? 1 : 0);
                } else if (i != 0 && j == 0) {
                    dp[i][j] = 0;
                } else {
                    if (s2[i] == s1[j]) {
                        dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                    } else {
                        dp[i][j] = dp[i][j-1];
                    }

                }
            }
        }

        return dp[s2.length()-1][s1.length()-1];
    }
};
