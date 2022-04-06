// @Title: Minimum Path Sum
// @Author: colinjxc
// @Date: 2022-01-11T00:13:26+08:00
// @URL: https://leetcode-cn.com/problems/minimum-path-sum


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        if (m == 0 || n == 0) {
            return 0;
        }
        
        // 初始化矩阵
        vector<vector<int>> stepSum(m+1, vector<int>(n+1, INT_MAX));
        
        int from = 0;
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= n; k++) {
                if (j != 1 || k != 1) 
                    from = std::min(stepSum[j][k-1], stepSum[j-1][k]);
                stepSum[j][k] = grid[j-1][k-1] + from;
            }
        }

        return stepSum[m][n];
    }
};
