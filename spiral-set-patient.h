//https://oj.leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    void setCircle(vector<vector<int> >& m, int ltx, int lty, int rbx, int rby, int& cnt) {
        for (int i = lty; i < rby; i++) m[ltx][i] = cnt++;
        for (int i = ltx; i < rbx; i++) m[i][rby] = cnt++;
        for (int i = rbx; i > ltx; i--) m[rbx][i] = cnt++;
        for (int i = rby; i > lty; i--) m[i][lty] = cnt++;
    }
    vector<vector<int> > generateMatrix(int n) {
        if (n == 0) return (vector<vector<int> >());
        vector<vector<int> > v(n);
        for (int i = 0; i < n; i++) v[i].resize(n);

        int cnt = 1;
        int ltx = 0, lty = 0;
        int rbx = n - 1, rby = n - 1;
        while (ltx < rbx) {
            setCircle(v, ltx, lty, rbx, rby, cnt);
            ltx++;
            lty++;
            rbx--;
            rby--;
        }
        if (n % 2 == 1) v[ltx][lty] = cnt;
        return v;
    }
};
