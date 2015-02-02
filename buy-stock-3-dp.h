//https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return 0;

        vector<int> left(prices.size());
        vector<int> right(prices.size());

        int mi = prices[0];
        left[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            left[i] = prices[i] - mi > left[i-1] ? prices[i] - mi : left[i-1];
            mi = mi < prices[i] ? mi : prices[i];
        }

        int ma = prices[prices.size()-1];
        right[right.size()-1] = 0;
        for (int i = right.size()-2; i >= 0; i--) {
            right[i] = ma - prices[i] > right[i+1] ? ma - prices[i] : right[i+1];
            ma = ma > prices[i] ? ma : prices[i];
        }

        int ret = left[0] + right[0];
        for (int i = 1; i < left.size(); i++) {
            ret = ret > left[i] + right[i] ? ret : left[i] + right[i];
        }

        return ret;
    }
};
