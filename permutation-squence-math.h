//https://oj.leetcode.com/problems/permutation-sequence/

class Solution {
public:
    int getNum(bool ext[], int k) {
        int i = 0;
        while (k >= 0) {
            if (!ext[i]) k--;
            i++;
        }
        ext[i-1] = true;
        return i;
    }
    string getPermutation(int n, int k) {
        int fact[9] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        bool ext[9] = {false, false, false, false, false, false, false, false, false};

        k--;
        string ret = "";
        int idx = n - 2;

        while (idx >= 0) {
            ret.append(1, '0' + getNum(ext, k / fact[idx]));
            k %= fact[idx];
            idx--;
        }

        ret.append(1, '0' + getNum(ext, 0));
        return ret;
    }
};
