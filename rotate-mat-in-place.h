//https://oj.leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (n == 1) return;

        int tmp;
        double mid = (n - 1.0) / 2;
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n-i-1; j++) {
                double diff0 = i - mid;
                double diff1 = j - mid;
                tmp = matrix[i][j];
                matrix[i][j] = matrix[(int)(mid-diff1)][(int)(mid+diff0)];
                matrix[(int)(mid-diff1)][(int)(mid+diff0)] = matrix[(int)(mid-diff0)][(int)(mid-diff1)];
                matrix[(int)(mid-diff0)][(int)(mid-diff1)] = matrix[(int)(mid+diff1)][(int)(mid-diff0)];
                matrix[(int)(mid+diff1)][(int)(mid-diff0)] = tmp;
            }
        }
    }
};
