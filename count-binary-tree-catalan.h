//https://oj.leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp;
        dp.resize(n+1);
        dp[0] = 1;

        int tmp = 0;
        for (int i = 1; i <= n; i++) {
            tmp = 0;
            for (int j = 0; j < i; j++) {
                tmp += (dp[j] * dp[i-j-1]);
            }
            dp[i] = tmp;
        }

        return dp[n];
    }
};
