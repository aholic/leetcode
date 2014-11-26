//https://oj.leetcode.com/problems/combinations/

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        if (n == 0 || k == 0 || n < k) return (vector<vector<int> >());
        vector<vector<vector<vector<int> > > > mat;
        mat.resize(n+1);
        for (int i = 0; i <= n; i++) mat[i].resize(k+1);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i && j <= k; j++) {
                if (mat[i-1][j-1].empty()) {
                    mat[i][j].push_back(vector<int>(1,i));
                } else {
                    for (int m = 0; m < mat[i-1][j-1].size(); m++) {
                        vector<int> tmp = mat[i-1][j-1][m];
                        tmp.push_back(i);
                        mat[i][j].push_back(tmp);
                    }    
                }
                for (int m = 0; m < mat[i-1][j].size(); m++) {
                    mat[i][j].push_back(mat[i-1][j][m]);
                }
            }
        }

        return mat[n][k];
    }
};
