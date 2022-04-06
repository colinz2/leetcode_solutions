// @Title: Unique Paths
// @Author: colinjxc
// @Date: 2018-12-10T22:06:00+08:00
// @URL: https://leetcode-cn.com/problems/unique-paths


class Solution {
public:
    //n行， m列
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths;
        vector<int> row(m + 1, 1);
        for (int i = 0; i <= n; i++) {
            paths.push_back(row);
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <=m; j++) {
                paths[i][j] = paths[i][j - 1] + paths[i - 1][j];
            }
        }
        return paths[n][m];
    }
};
