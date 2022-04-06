// @Title: Largest Rectangle in Histogram
// @Author: colinjxc
// @Date: 2022-01-31T22:59:36+08:00
// @URL: https://leetcode-cn.com/problems/largest-rectangle-in-histogram


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int cur = st.top(); st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                res = max(res, heights[cur] * width);
            }
            st.push(i);
        }
        return res;
    }
};
