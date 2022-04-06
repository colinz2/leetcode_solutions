// @Title: Factor Combinations
// @Author: colinjxc
// @Date: 2022-02-10T02:23:37+08:00
// @URL: https://leetcode-cn.com/problems/factor-combinations


class Solution {
public:
    vector<vector<int>> getFactors(int n) {

        function<vector<vector<int>>(int, int)> dfs = [&](int n, int start) {
            vector<vector<int>> res;
            for (int i = start; i*i <= n; i++) {
                if (n % i == 0) {
                    res.push_back({i, n / i});
                    for (auto &v : dfs(n / i, i)) {
                        v.push_back(i);
                        res.push_back(v);
                    }
                }
            }
            return res;
        };

        return dfs(n, 2);
    }
};
