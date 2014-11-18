//https://oj.leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;

        vector<vector<int> > vec;
        vec.resize(m);
        for (int i = 0; i < m; i++) vec[i].resize(n);

        for (int i = 0; i < m; i++) vec[i][0] = 1;
        for (int i = 0; i < n; i++) vec[0][i] = 1;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                vec[i][j] = vec[i-1][j] + vec[i][j-1];
            }
        }

        return vec[m-1][n-1];
    }
};
