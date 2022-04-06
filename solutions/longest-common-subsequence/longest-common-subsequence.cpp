// @Title: Longest Common Subsequence
// @Author: colinjxc
// @Date: 2022-01-24T12:04:34+08:00
// @URL: https://leetcode-cn.com/problems/longest-common-subsequence


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1));
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        return dp.back().back();
    }
};
