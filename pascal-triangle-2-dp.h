//https://oj.leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int k) {
        vector<int> c(k+1);

        c[0] = 1;
        for (int i = 1; i <= k; i++) {
            long long tmp = c[i-1] * ((long long) (k+1-i)) / i;
            c[i] = tmp;
        }

        return c;
    }
};
