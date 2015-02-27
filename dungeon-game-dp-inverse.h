//https://oj.leetcode.com/problems/dungeon-game/

class Solution {
public:
    int min(int a, int b) {
        return a < b ? a : b;
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }

    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        if (dungeon.size() == 0 || dungeon[0].size() == 0) return 0;
        int m = dungeon.size(), n = dungeon[0].size();

        int dp[m][n];
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i == m-1 && j == n-1) {
                    dp[i][j] = max(1, 1 - dungeon[i][j]);
                } else if (i == m-1 && j != n-1) {
                    dp[i][j] = max(dp[i][j+1] - dungeon[i][j], 1);
                } else if (i != m-1 && j == n-1) {
                    dp[i][j] = max(dp[i+1][j] - dungeon[i][j], 1);
                } else {
                    dp[i][j] = max(min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j], 1);
                }
            }
        }

        return dp[0][0];
    }
};
