//https://oj.leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;

        vector<vector<int> > vec;
        vec.resize(m);
        for (int i = 0; i < m; i++) vec[i].resize(n);

        int idx;
        for (idx = 0; idx < m && obstacleGrid[idx][0] != 1; idx++) vec[idx][0] = 1;
        for (; idx < m; idx++) vec[idx][0] = 0;

        for (idx = 0; idx < n && obstacleGrid[0][idx] != 1; idx++) vec[0][idx] = 1;
        for (; idx < n; idx++) vec[0][idx] = 0;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    vec[i][j] = 0;
                } else {
                    vec[i][j] = vec[i-1][j] + vec[i][j-1];
                }
            }
        }

        return vec[m-1][n-1];
    }
};
