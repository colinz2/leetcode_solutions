// @Title: Richest Customer Wealth
// @Author: colinjxc
// @Date: 2021-10-27T21:16:23+08:00
// @URL: https://leetcode-cn.com/problems/richest-customer-wealth


class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        vector<int> res;
        for (auto &v : accounts) {
            res.push_back(accumulate(v.begin(), v.end(), 0));
        }
        sort(res.begin(), res.end());
        return res.back();
    }
};
