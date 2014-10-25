//https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) return 0;

        vector<int> dp;
        dp.resize(prices.size());
        dp[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] >= prices[i-1]) {
                dp[i] = dp[i-1] + prices[i] - prices[i-1];
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp[dp.size()-1];
    }
};
