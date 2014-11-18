//https://oj.leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(int A[], int n) {
        int cnt[] = {0, 0, 0};
        for (int i = 0; i < n; i++) cnt[A[i]] += 1;

        for (int i = 0; i < cnt[0]; i++) A[i] = 0;
        for (int i = cnt[0]; i < cnt[0] + cnt[1]; i++) A[i] = 1;
        for (int i = cnt[0] + cnt[1]; i < n; i++) A[i] = 2;
    }
};
