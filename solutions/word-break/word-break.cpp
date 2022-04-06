// @Title: Word Break
// @Author: colinjxc
// @Date: 2022-01-22T14:08:43+08:00
// @URL: https://leetcode-cn.com/problems/word-break


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return false;
        vector<bool> dp(s.size(), false);
        dp[0] = true;

        for(int i = 1; i <= s.size(); i++) {
            for (auto &word : wordDict) {
                auto wordLen = word.size();
                if (i >= wordLen && word == s.substr(i-wordLen, wordLen))
                    dp[i] = dp[i] || dp[i - wordLen];
            }
        }
        return dp[s.size()];
    }
};
