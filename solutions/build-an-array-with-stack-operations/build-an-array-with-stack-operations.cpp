// @Title: Build an Array With Stack Operations
// @Author: colinjxc
// @Date: 2022-01-28T01:59:06+08:00
// @URL: https://leetcode-cn.com/problems/build-an-array-with-stack-operations


class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int cnt_neq = 0;
        for (int i = 1, j = 0; i <= n && j < target.size(); i++) {
            res.emplace_back("Push");
            if (target[j] != i) {
                res.emplace_back("Pop");
            } else {
                j++;
            }
        }
        return res;
    }
};
