//https://oj.leetcode.com/problems/triangle/

class Solution {
public:
    int minimumTotal(vector<vector<int> > &tri) {
        for (int i = 1; i < tri.size(); i++) {
            for (int j = 0; j < tri[i].size(); j++) {
                if (j == 0) {
                    tri[i][j] += tri[i-1][j];
                } else if (j == tri[i].size() - 1) {
                    tri[i][j] += tri[i-1][j-1];
                } else {
                    tri[i][j] += min(tri[i-1][j-1], tri[i-1][j]);
                }
            }
        }

        int ret = tri[tri.size()-1][0];
        for (int i = 1; i < tri[tri.size()-1].size(); i++) {
            if (ret > tri[tri.size()-1][i]) {
                ret = tri[tri.size()-1][i];
            }
        }

        return ret;
    }
};
