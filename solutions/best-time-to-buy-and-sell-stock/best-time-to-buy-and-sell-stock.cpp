// @Title: Best Time to Buy and Sell Stock
// @Author: colinjxc
// @Date: 2022-01-28T15:39:57+08:00
// @URL: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            max_profit = std::max(max_profit, prices[i] - min_price);
            min_price = std::min(min_price, prices[i]);
        }
        return max_profit;
    }
};
