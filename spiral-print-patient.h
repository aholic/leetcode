//https://oj.leetcode.com/problems/spiral-matrix/

class Solution {
public:
    bool getCircle(vector<int> &ret,vector<vector<int> > &matrix, int ltx, int lty, int rbx, int rby) {
        for (int y = lty; y <= rby; y++) ret.push_back(matrix[ltx][y]);
        for (int x = ltx + 1; x <= rbx; x++) ret.push_back(matrix[x][rby]);
        if (ltx == rbx || lty == rby) return false;

        for (int y = rby - 1; y >= lty; y--) ret.push_back(matrix[rbx][y]);
        for (int x = rbx - 1; x >= ltx + 1; x--) ret.push_back(matrix[x][lty]);
        if (rbx - ltx <= 1 || rby - lty <= 1) return false;
        return true;
    }
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        if (matrix.size() == 0) return ret;
        if (matrix[0].size() == 0) return ret;

        int ltx = 0, lty = 0;
        int rbx = matrix.size() - 1;
        int rby = matrix[0].size() - 1;

        while (getCircle(ret, matrix, ltx, lty, rbx, rby)) {
            ltx++;
            lty++;
            rbx--;
            rby--;
        }
        return ret;
    }
};
