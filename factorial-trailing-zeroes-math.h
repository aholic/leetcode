//https://oj.leetcode.com/problems/factorial-trailing-zeroes/

class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 5) return 0;
        return trailingZeroes(n/5) + n/5;
    }
};
