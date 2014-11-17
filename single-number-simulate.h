//https://oj.leetcode.com/problems/single-number-ii/

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ans = 0, tmp = 0;
        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            tmp = (1 << i);
            cnt = 0;

            for (int j = 0 ; j < n; j++) {
                if ((tmp & A[j]) != 0) cnt++;
            }

            if (cnt % 3 != 0) ans |= tmp;
        }
        return ans;
    }
};
