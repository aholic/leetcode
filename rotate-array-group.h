//https://oj.leetcode.com/problems/rotate-array/

class Solution {
public:
    void adjustGroup(int nums[], int n, int k, int start) {
        int tmp = nums[start];
        int i = start;

        do {
            nums[i] = nums[(i+n-k) % n];
            i = (i+n-k) % n;
        } while (i != start);

        nums[start+k] = tmp;
    }

    int gcd(int a, int b) {
        int mi = a < b ? a : b;
        int ma = a > b ? a : b;
        if (ma % mi == 0) return mi;
        return gcd(mi, ma % mi);
    }

    void rotate(int nums[], int n, int k) {
        k %= n;
        if (n == 0 || k == 0) return;

        int groupNum = gcd(n, k);
        for (int i = 0; i < groupNum; i++) {
            adjustGroup(nums, n, k, i);
        }
    }
};
