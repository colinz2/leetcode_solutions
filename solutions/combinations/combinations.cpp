// @Title: Combinations
// @Author: colinjxc
// @Date: 2022-03-07T09:58:41+08:00
// @URL: https://leetcode-cn.com/problems/combinations


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(res, 1, tmp, n, k);
        return res;
    }

    void backtrack(vector<vector<int>>& res, int index, vector<int> &tmp, int n, int k) {
        if (tmp.size() == k) {
            res.push_back(tmp);
        }
        for (int i = index; i <= n; i++) {
            tmp.push_back(i);
            backtrack(res, i+1, tmp, n, k);
            tmp.pop_back();
        }
    }
};
