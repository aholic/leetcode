//https://oj.leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int mi = INT_MAX;
        int ma = INT_MIN;
        unordered_map<int, bool> ext;
        for (int i = 0; i < n; i++) {
            if (A[i] > 0) {
                ext.insert(pair<int, bool>(A[i], true));
                ma = ma > A[i] ? ma : A[i];
                mi = mi < A[i] ? mi : A[i];
            }
        }

        if (mi != 1) return 1;
        if (ma - mi + 1 == ext.size()) return ma+1;

        for (int i = mi; i <= ma; i++) {
            if (ext.find(i) == ext.end()) return i;
        }
    }
};
