//https://oj.leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findKth(int a[], int m, int b[], int n, int k) {
        if (m > n) return findKth(b, n, a, m, k);
        if (m == 0) return b[k-1];
        if (k == 1) return a[0] < b[0] ? a[0] : b[0];

        int pa = m > k / 2 ? k / 2 : m;
        int pb = k - pa;
        if (a[pa-1] > b[pb-1]) {
            return findKth(a, pa, b+pb, n-pb, k-pb);
        } else if (a[pa-1] < b[pb-1]) {
            return findKth(a+pa, m-pa, b, pb, k-pa);
        } else {
            return a[pa-1];
        }
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total % 2 == 1) {
            return findKth(A, m, B, n, total / 2 + 1);
        } else {
            return (findKth(A, m, B, n, total / 2) + findKth(A, m, B, n, total / 2 + 1)) / 2;
        }
    }
};
