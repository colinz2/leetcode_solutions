// @Title: Daily Temperatures
// @Author: realzhangm
// @Date: 2021-10-29T16:51:43+08:00
// @URL: https://leetcode-cn.com/problems/daily-temperatures


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 单调栈，保存位置
        int len = temperatures.size();
        vector<int> res(len, 0);
        vector<int> st(len, 0);

        int stLen = 0;

        for (int i = 0; i < len; i++) {
            while (stLen > 0 && temperatures[i] > temperatures[st[stLen-1]]) {
                res[st[stLen-1]] = i - st[stLen-1];
                stLen--;
            }
            st[stLen++] = i;
        }

        return res;
    }
};
