//https://oj.leetcode.com/problems/word-break/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len = s.length();
        bool dp[len];

        for (int i = 0; i < len; i++) {
            dp[i] = (dict.find(s.substr(0,i+1)) != dict.end());
            if (dp[i]) continue;

            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.find(s.substr(j+1, i-j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[len-1];
    }
};
