// @Title: Best Time to Buy and Sell Stock II
// @Author: realzhangm
// @Date: 2021-11-01T18:39:55+08:00
// @URL: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            // 把所有可能的利润都算上，自然就是最大的总利润
            if (prices[i] > prices[i - 1]) {
                res += prices[i] - prices[i - 1];
            }
        }
        return res;
    }
};
