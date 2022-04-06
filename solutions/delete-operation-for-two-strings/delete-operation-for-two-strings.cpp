// @Title: Delete Operation for Two Strings
// @Author: colinjxc
// @Date: 2022-01-24T02:36:38+08:00
// @URL: https://leetcode-cn.com/problems/delete-operation-for-two-strings


class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j]
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));
        for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for (int i = 0; i <= word2.size(); i++) dp[0][i] = i;

        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    int del1 = 1 + dp[i-1][j];
                    int del2 = 1 + dp[i][j-1];
                    dp[i][j] = std::min(del1, del2);
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
