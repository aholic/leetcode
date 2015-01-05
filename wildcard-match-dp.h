//https://oj.leetcode.com/problems/wildcard-matching/

class Solution {
public:
    int getLongestStar(const char *p, int len) {
        int ret = 0;
        while (ret < len && p[ret] == '*') ret++;
        return ret;
    }

    bool isMatch(const char *s, const char *p) {
        int slen = strlen(s);
        int plen = strlen(p);

        if (slen == 0 && plen == 0) return true;
        if (plen == 0) return false;

        int longestStar = getLongestStar(p, plen);
        if (slen == 0) return plen == longestStar;

        vector<bool> dp(slen);

        for (int i = 0; i < plen; i++) {
            for (int j = 0; j < slen; j++) {
                if (i == 0 && j == 0) {
                    dp[j] = (p[i] == s[i] || p[i] == '*' || p[i] == '?');
                } else if (i == 0 && j != 0) {
                    dp[j] = dp[j-1] && p[i] == '*';
                } else if (i != 0 && j == 0) {
                    dp[j] = (p[i] == '*' && dp[j])
                        || (p[i] == s[j] && longestStar >= i);
                } else {
                    dp[j] = ((p[i] == '*' && dp[j])
                        || (p[i] == s[j] && dp[j-1])
                        || (p[i] == '*' && dp[j-1]));
                }
            }
        }

        return dp[slen-1];
    }
};
