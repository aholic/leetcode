//https://oj.leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(int A[], int n) {
        if (n == 0) return;

        int tmp;
        int low = 0, high = n - 1;
        while (low < n && A[low] == 0) low++;
        while (high >= 0 && A[high] == 2) high--;
        if (high <= low) return;

        for (int i = low; i <= high;) {
            if (A[i] == 0) {
                A[i] = A[low];
                A[low] = 0;
                while (low < n && A[low] == 0) low++;
                if (low == n) break;
                i = low;
            } else if (A[i] == 1) {
                i++;
            } else {
                A[i] = A[high];
                A[high] = 2;
                while (high >= 0 && A[high] == 2) high--;
                if (high == -1) break;
            }
            if (low >= high) break;
        }
    }
};
