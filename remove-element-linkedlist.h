//https://oj.leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] == elem) cnt++;
        }

        int j = n - cnt;
        for (int i = 0; i < n - cnt; i++) {
            if (A[i] == elem) {
                while (j < n && A[j] == elem) j++;
                A[i] = A[j++];
            }
        }
        return n-cnt;
    }
};
