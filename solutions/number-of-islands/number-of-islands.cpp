// @Title: Number of Islands
// @Author: colinjxc
// @Date: 2022-02-13T20:08:22+08:00
// @URL: https://leetcode-cn.com/problems/number-of-islands


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid.front().size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int res = 0;

        function<int(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || j < 0 || i == m || j == n) {
                return 0;
            }
            if (vis[i][j] || grid[i][j] == '0') return 0;
            vis[i][j] = true;
            return 1 + dfs(i, j-1) + dfs(i-1,j) + dfs(i+1,j) + dfs(i,j+1);
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    res += (dfs(i, j) > 0);
                }
            }
        }

        return res;
    }
};
