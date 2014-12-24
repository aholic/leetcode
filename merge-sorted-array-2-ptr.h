//https://oj.leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int ia = m - 1;
        int ib = n - 1;
        int itr = n + m - 1;
        while (itr >= 0) {
            if (ia >= 0 && ib >= 0) {
                if (A[ia] > B[ib]) {
                    A[itr--] = A[ia--];
                } else {
                    A[itr--] = B[ib--];
                }    
            } else if (ia >= 0) {
                A[itr--] = A[ia--];
            } else {
                A[itr--] = B[ib--];
            }
        }
    }
};
