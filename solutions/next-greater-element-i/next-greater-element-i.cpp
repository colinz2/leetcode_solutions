// @Title: Next Greater Element I
// @Author: realzhangm
// @Date: 2021-10-29T19:06:44+08:00
// @URL: https://leetcode-cn.com/problems/next-greater-element-i


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        stack<int> st;
        map<int, int> m;
        // 先遍历 nums2 啊，再遍历 nums1，类似每日温度
        for (auto &v : nums2) {
            m[v] = -1;
            while (!st.empty() && v > st.top()) {
                m[st.top()] = v;
                st.pop();
            }
            st.push(v);
        }

        for (int i = 0; i < nums1.size(); i++) {
            res[i] = m[nums1[i]];
        }
        return res;
    }
};
