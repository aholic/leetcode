//https://oj.leetcode.com/problems/search-for-a-range/

class Solution {
public:
    int first_of(int A[], int n, int target) {
        if (n == 0 || A[0] > target || A[n-1] < target) return -1;
        int l = 0, r = n - 1, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (A[mid] >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (A[l] != target) return -1;
        return l;
    }

    int last_of(int A[], int n, int target) {
        if (n == 0 || A[0] > target || A[n-1] < target) return -1;
        int l = 0, r = n - 1, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (A[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (A[r] != target) return -1;
        return r;
    }

    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret(2);
        ret[0] = first_of(A, n, target);
        ret[1] = last_of(A, n, target);
        return ret;
    }
};
