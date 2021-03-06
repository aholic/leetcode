//https://oj.leetcode.com/problems/sqrtx/

class Solution {
public:
    int sqrt(int x) {
        // max answer for int x
        double d0 = 46340;
        double d1 = 0x7fffffff;
        if (d0 * d0 <= x) return (int) d0;

        while (d1 - d0 >= 1) {
            d1 = d0;
            d0 = d0 / 2 + x / 2.0 / d0;
        }
        return (int) d0;
    }
};
