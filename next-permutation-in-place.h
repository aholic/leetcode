//https://oj.leetcode.com/problems/next-permutation/

class Solution {
public:
    void swa(vector<int> &num, int i, int j) {
        int tmp = num[i];
        num[i] = num[j];
        num[j] = tmp;
    }

    void nextPermutation(vector<int> &num) {
        int down = num.size() - 1;
        while (down >= 1 && num[down] <= num[down-1]) down--;

        for (int low = down, high = num.size() - 1; low < high; low++,high--) {
            swa(num, low, high);
        }

        if (down == 0) return;
        for (int i = down; i < num.size(); i++) {
            if (num[i] > num[down-1]) {
                swa(num, i, down-1);
                return;
            }
        }
    }
};
