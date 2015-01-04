//https://oj.leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(int A[], int n) {
        if (n <= 2) return 0;

        int l = 0, ret = 0, r = 0, tmp;
        int high;
        while (l < n - 1) {
            if (A[l] <= A[l+1]) {
                l++;
                continue;
            }
            r = l + 1;

            while (r < n && A[r] < A[l]) r++;

            if (r == n) break;

            tmp = A[l] < A[r] ? A[l] : A[r];
            for (int i = l + 1 ; i < r; i++) {
                ret += (tmp > A[i] ? tmp - A[i] : 0);
            }

            l = r;
        }

        if (r-l < 2) return ret;

        int newl = l;
        r--;
        while (r > newl) {
            if (A[r] <= A[r-1]) {
                r--;
                continue;
            }
            l = r-1;

            while (l >= newl && A[l] < A[r]) l--;

            if (l == newl - 1) break;

            tmp = A[l] < A[r] ? A[l] : A[r];
            for (int i = l + 1 ; i < r; i++) {
                ret += (tmp > A[i] ? tmp - A[i] : 0);
            }

            r = l;
        }

        return ret;
    }
};
