// @Title: Number of Enclaves
// @Author: colinjxc
// @Date: 2022-02-12T18:01:38+08:00
// @URL: https://leetcode-cn.com/problems/number-of-enclaves


class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
      int cnt = 0, m = grid.size(), n = grid.front().size();
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          cnt += grid[i][j];
        }
      }

      function<void(int,int)> dfsSubtract = [&](int i, int j) {
        if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == 0) {
          return;
        }
        grid[i][j] = 0;
        cnt--;
        dfsSubtract(i, j-1);
        dfsSubtract(i-1, j);
        dfsSubtract(i, j+1);
        dfsSubtract(i+1, j);
      };

      for (int i = 0; i < m; i++) {
        dfsSubtract(i, 0);
        dfsSubtract(i, n-1);
      }

      for (int i = 0; i < n; i++) {
        dfsSubtract(0, i);
        dfsSubtract(m - 1, i);
      }
      return cnt;
    }
};
