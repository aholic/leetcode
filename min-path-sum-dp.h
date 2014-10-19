//https://oj.leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int> > dp;
        dp.resize(m);
        for (int i = 0; i < dp.size(); i++) dp[i].resize(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                } else if (i == 0) {
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                }  else if (j == 0) {
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                } else {
                    dp[i][j] = (dp[i-1][j] < dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]) + grid[i][j];
                }
            }
        }

        return dp[m-1][n-1];
    }
};
