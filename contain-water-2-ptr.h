//https://oj.leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int> &h) {
        if (h.size() < 2) return 0;
        int l = 0, r = h.size() - 1;
        int ans = 0;
        while (l < r) {
            ans = max(min(h[l], h[r]) * (r-l), ans);
            if (h[r] > h[l]) {
                l++;
            } else {
                r--;
            }
        }

        return ans;
    }
};
