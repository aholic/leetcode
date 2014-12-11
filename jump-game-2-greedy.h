//https://oj.leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(int A[], int n) {
        if (n <= 1) return 0;
        int *steps = new int [n];

        steps[0] = 0;
        int ma = 0;
        for (int i = 0; i < n; i++) {
            for (int j = ma + 1; j <= i + A[i] && j < n; j++) {
                steps[j] = steps[i] + 1;
                ma = j;
            }
        }
        int ret = steps[n-1];
        delete [] steps;
        return ret;
    }
};
