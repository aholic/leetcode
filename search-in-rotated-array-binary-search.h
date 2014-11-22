//https://oj.leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(int A[], int n, int key) {
        if (n == 0) return -1;

        int l = 0, r = n - 1;
        int mid = l + (r-l) / 2;
        while (l <= r) {
            if (A[mid] >= A[l] && A[mid] >= A[r]) {
                if (A[mid] < key) {
                    l = mid + 1;
                } else if (A[mid] > key) {
                    if (A[l] > key) {
                        l = mid + 1;
                    } else if (A[l] < key) {
                        r = mid - 1;
                    } else {
                        return l;
                    }
                } else {
                    return mid;
                }
            } else if (A[mid] <= A[l] && A[mid] <= A[r]) {
                if (A[mid] > key) {
                    r = mid - 1;
                } else if (A[mid] < key) {
                    if (A[r] > key) {
                        l = mid + 1;
                    } else if (A[r] < key) {
                        r = mid - 1;
                    } else {
                        return r;
                    }
                } else {
                    return mid;
                }
            } else if (A[mid] >= A[l] && A[mid] <= A[r]) {
                if (A[mid] > key) {
                    r = mid - 1;
                } else if (A[mid] < key) {
                    l = mid + 1;
                } else {
                    return mid;
                }
            }
            mid = l + (r-l) / 2;
        }
        return -1;
    }
};
