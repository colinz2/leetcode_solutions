// @Title: Best Time to Buy and Sell Stock
// @Author: realzhangm
// @Date: 2021-11-01T17:40:12+08:00
// @URL: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int max = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] > buy) {
                max = std::max(max, prices[i] - buy);
            } else {
                buy = prices[i];
            }
        }  
        return max;
    }
};
