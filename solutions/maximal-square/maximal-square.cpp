// @Title: Maximal Square
// @Author: colinjxc
// @Date: 2022-01-31T21:26:40+08:00
// @URL: https://leetcode-cn.com/problems/maximal-square


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix.back().size();
        int res = 0;
        vector<vector<int>> dp(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = std::min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                    }
                    res = std::max(res, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return res * res;
    }
};
