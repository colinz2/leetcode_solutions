// @Title: Richest Customer Wealth
// @Author: colinjxc
// @Date: 2021-10-27T21:37:23+08:00
// @URL: https://leetcode-cn.com/problems/richest-customer-wealth


class Solution(object):
    def maximumWealth(self, accounts):
        """
        :type accounts: List[List[int]]
        :rtype: int
        """
        return max([sum(account) for account in accounts])
