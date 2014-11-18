//https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return 0;

        int i = 1;
        while (i < n && A[i] != A[i-1]) i++;
        if (i >= n) return i;
        int j = i + 1;

        while (true) {
            while (j < n && A[j] == A[i]) j++;
            if (j >= n) return i;

            A[i] = A[j];

            while (j < n && A[j] == A[i]) j++;
            i++;

            if (j >= n) return i;
        }
    }
};
