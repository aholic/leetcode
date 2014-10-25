//https://oj.leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(int A[], int n) {
        int pos = 0, next = 0;
        while (next < n-1) {
            next = pos;
            for (int i = pos; i < n && i <= pos + A[pos]; i++) {
                if (next < A[i] + i) {
                    next = A[i] + i;
                }
            }
            if (next == pos) return false;
            pos = next;
        }
        return true;
    }
};
