// @Title: Integer Break
// @Author: colinjxc
// @Date: 2018-12-10T21:15:42+08:00
// @URL: https://leetcode-cn.com/problems/integer-break


class Solution {
public:
    int integerBreak(int n) {
        vector<int>memo(n + 1, 1);
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                int max_tmp = max(j * (i - j), j * memo[i - j]);
                memo[i] = max(memo[i], max_tmp);
            }
        }
        return memo[n];
    }
};
