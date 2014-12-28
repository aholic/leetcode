//https://oj.leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool negative = (dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0);
        long long a = dividend;
        long long b = divisor;

        a = a < 0 ? -a : a;
        b = b < 0 ? -b : b;

        long long rst = 0;

        while (a >= b) {
            long long sum = b;
            long long tmp = 1;
            while (sum + sum < a) {
                tmp <<= 1;
                sum <<= 1;
            }
            rst += tmp;
            a -= sum;
        }

        long long m = 0x7fffffff;
        if (negative && rst > m+1 || !negative && rst > m) return 0x7fffffff;

        return negative ? -rst : rst;
    }
};
