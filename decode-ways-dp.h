//https://oj.leetcode.com/problems/decode-ways/

class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0 || s[0] == '0') return 0;
        if (s.length() == 1) return 1;
        if (s.length() == 2) {
            if (s[1] == '0' && s[0] > '2') return 0;
            if (s[1] == '0') return 1;
            if (s[0] == '2' && s[1] <= '6') return 2;
            if (s[0] == '1') return 2;
        }

        int dp[s.length()];
        dp[0] = 1;
        if (s[1] == '0' && s[0] > '2') return 0;
        if (s[1] == '0') {
            dp[1] = 1;
        } else if (s[0] == '2' && s[1] <= '6' || s[0] == '1') {
            dp[1] = 2;
        } else {
            dp[1] = 1;
        }

        for (int i = 2; i < s.length(); i++) {
            if (s[i] == '0' && (s[i-1] == '0' || s[i-1] > '2')) return 0;

            if (s[i] == '0') {
                dp[i] = dp[i-2];
                continue;
            }

            if (s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6') {
                dp[i] = dp[i-2] + dp[i-1];
                continue;
            }

            dp[i] = dp[i-1];
        }

        return dp[s.length()-1];
    }
};
