// @Title: Lexicographical Numbers
// @Author: colinjxc
// @Date: 2022-02-07T19:45:57+08:00
// @URL: https://leetcode-cn.com/problems/lexicographical-numbers


class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i <= 9; i++) {
            dfs(i, n, res);
        }
        return res;
    }

    void dfs(int curr, int n, vector<int>& res) {
        if (curr > n) return;
        res.push_back(curr);
        for (int i = 0; i <= 9; i++) {
            dfs(curr*10 + i, n, res);
        }
    }
};
