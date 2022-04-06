// @Title: Set Matrix Zeroes
// @Author: colinjxc
// @Date: 2022-03-01T22:56:28+08:00
// @URL: https://leetcode-cn.com/problems/set-matrix-zeroes


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.front().size();
        vector<pair<int,int>> zeroPoints;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    zeroPoints.push_back({i, j});
                }
            }
        }
        for (auto &p : zeroPoints) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == p.first || j == p.second) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
    }
};
