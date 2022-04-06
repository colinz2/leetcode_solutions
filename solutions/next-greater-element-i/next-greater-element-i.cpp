// @Title: Next Greater Element I
// @Author: colinjxc
// @Date: 2022-01-25T10:22:44+08:00
// @URL: https://leetcode-cn.com/problems/next-greater-element-i


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        map<int, int> greaterMap;

        for (auto& n : nums2) {
            while (!st.empty() && n > st.top()) {
                greaterMap[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }
        
        vector<int> res;
        for (auto& n : nums1) {
            auto itr = greaterMap.find(n);
            if (itr != greaterMap.end()) {
                res.push_back(itr->second);
            } else {
                res.push_back(-1);
            }
        }

        return res;
    }
};
