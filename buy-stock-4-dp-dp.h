//https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    int max(int a, int b) {
        return a > b ? a : b;
    }

    int maxProfit(int k, vector<int> &prices) {
        if (k <= 0) return 0;
        if (prices.size() <= 1) return 0;

        int days = prices.size();
        if (k >= days / 2) return quick(prices);

        int sellAtLast[k+1];
        int ans[k+1];

        for (int i = 0; i <= k; i++) {
            sellAtLast[i] = 0;
            ans[i] = 0;
        }

        for (int i = 1; i < days; i++) {
            int diff = prices[i] - prices[i-1];
            for (int j = k; j >= 1; j--) {
                sellAtLast[j] = max(sellAtLast[j] + diff, ans[j-1] + max(0, diff));
                ans[j] = max(sellAtLast[j], ans[j]);
            }
        }

        return ans[k];
    }

    int quick(const vector<int> &prices) {
        int ret = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                ret += (prices[i] - prices[i-1]);
            }
        }
        return ret;
    }
};
