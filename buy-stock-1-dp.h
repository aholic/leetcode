//https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 0) return 0;

        int mi = prices[0];
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            mi = mi > prices[i-1] ? prices[i-1] : mi;
            if (prices[i] - mi > ans) {
                ans = prices[i] - mi;
            }
        }

        return ans;
    }
};
