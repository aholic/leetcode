//https://oj.leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        if (num.size() == 1) return 0;

        int l = 0;
        int r = num.size() - 1;
        int m = l + (r - l) / 2;

        while (l <= r) {
            m = l + (r - l) / 2;
            if (m == 0 && num[m] > num[m+1]) return m;
            if (m == num.size() - 1 && num[m-1] < num[m]) return m;

            if ((m == 0 && num[m] < num[m+1]) 
                || (m == num.size() - 1 && num[m-1] < num[m]) 
                || (num[m-1] < num[m] && num[m] < num[m+1])) {
                l = m + 1;
            } else if ((m == 0 && num[m] > num[m+1])
                || (m == num.size() - 1 && num[m-1] > num[m])
                || (num[m-1] > num[m] && num[m] > num[m+1])) {
                r = m - 1;
            } else if (num[m] > num[m+1] && num[m] > num[m-1]) {
                return m;
            } else {
                l = m + 1;
            }
        }
    }
};
