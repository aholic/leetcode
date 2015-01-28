//https://oj.leetcode.com/problems/scramble-string/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;

        int len = s1.length();
        bool dp[len][len][len];

        for (int l = 0; l < len; l++) {
            for (int i = 0; i + l < len; i++) {
                for (int k = 0; k + l < len; k++) {
                    if (l == 0) {
                        dp[i][i+l][k] = s1[i] == s2[k];
                        continue;
                    }

                    dp[i][i+l][k] = false;

                    for (int m = i; m < i + l; m++) {
                        if (dp[i][m][k] && dp[m+1][i+l][k+m-i+1] || dp[m+1][i+l][k] && dp[i][m][i+l+k-m]) {
                            dp[i][i+l][k] = true;
                            break;
                        }
                    }
                }
            }
        }

        return dp[0][len-1][0];
    }
};
