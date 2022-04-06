// @Title: Video Stitching
// @Author: colinjxc
// @Date: 2021-07-07T14:39:50+08:00
// @URL: https://leetcode-cn.com/problems/video-stitching


class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> dp(time+1, time+1);
        dp[0] = 0;

        for (int i = 1; i <= time; i++) {
            for (auto &clip : clips) {
                if (clip[0] <=i && i <= clip[1]) {
                    dp[i] = std::min(dp[i], dp[clip[0]] + 1);
                }
            }
        }
        return dp[time] == time+1 ? -1 : dp[time];
    }
};
