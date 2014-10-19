//https://oj.leetcode.com/problems/powx-n/

class Solution {
public:
    double pow(double x, int n) {
        if (n == 1) return x;
        if (n == 0) return 1;
        if (n == -1) return 1/x;

        if (n % 2 == 0) {
            double tmp = pow(x, n/2);
            return tmp * tmp;
        } else {
            double tmp = pow(x, (n-1)/2);
            return tmp * tmp * x;
        }
    }
};
