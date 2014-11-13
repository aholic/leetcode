//https://oj.leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n == 0) return 0;

        int *dp = new int[n];
        dp[0] = A[0];
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i-1] > 0 ? dp[i-1] + A[i] : A[i];
        }

        int ret = A[0];
        for (int i = 0; i < n; i++) {
            if (dp[i] > ret) ret = dp[i];
        }
        delete [] dp;

        return ret;
    }
};
