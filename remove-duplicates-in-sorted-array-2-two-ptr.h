//https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;

        int i = 2;
        while (i < n && (A[i] != A[i-1] || A[i] != A[i-2])) i++;
        if (i >= n) return n;

        int j = i + 1;
        while (j < n && A[i] == A[j]) j++;

        while (j < n) {
            A[i++] = A[j++];
            while (j < n && A[j] == A[i-1] && A[j] == A[i-2]) j++;
        }

        return i;
    }
};
