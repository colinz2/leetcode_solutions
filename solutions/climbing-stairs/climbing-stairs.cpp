// @Title: Climbing Stairs
// @Author: colinjxc
// @Date: 2022-02-09T22:48:30+08:00
// @URL: https://leetcode-cn.com/problems/climbing-stairs


class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        vector<int> dp(n+1);
        dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
