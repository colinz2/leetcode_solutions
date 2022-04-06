// @Title: 每日温度
// @Author: colinjxc
// @Date: 2022-02-08T20:37:07+08:00
// @URL: https://leetcode-cn.com/problems/iIQa4I


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        
        stack<int> st;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return res;
    }
};
