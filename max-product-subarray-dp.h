//https://oj.leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int max3(int a, int b, int c) {
        int ret = a > b ? a : b;
        ret = ret > c ? ret : c;
        return ret;
    }
    int min3(int a, int b, int c) {
        int ret = a < b ? a : b;
        ret = ret < c ? ret : c;
        return ret;
    }

    int maxProduct(int A[], int n) {
        if (n == 0) return 0;

        int *maxVal = new int [n];
        int *minVal = new int [n];

        maxVal[0] = minVal[0] = A[0];
        for (int i = 1; i < n; i++) {
            maxVal[i] = max3(maxVal[i-1]*A[i], A[i], minVal[i-1]*A[i]);
            minVal[i] = min3(maxVal[i-1]*A[i], A[i], minVal[i-1]*A[i]);
        }

        int ret = maxVal[0];
        for (int i = 1; i < n; i++) {
            if (maxVal[i] > ret) ret = maxVal[i];
        }

        delete [] maxVal;
        delete [] minVal;

        return ret;
    }
};
