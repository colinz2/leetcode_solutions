// @Title: Spiral Matrix
// @Author: colinjxc
// @Date: 2022-02-09T14:38:29+08:00
// @URL: https://leetcode-cn.com/problems/spiral-matrix


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int up = 0, down = matrix.size() - 1;
        int left = 0, right = matrix.front().size() - 1;
        vector<int> res;
        for (;;) {
            for (int i = left; i <= right; i++) res.push_back(matrix[up][i]);
            if (++up > down) break;
            
            for (int i = up; i <= down;i++) res.push_back(matrix[i][right]);
            if (--right < left) break;
            
            for (int i = right; i >= left; i--) res.push_back(matrix[down][i]);
            if (--down < up) break;
            
            for (int i = down; i >= up; i--) res.push_back(matrix[i][left]);
            if (++left > right) break;
        }
        return res;
    }
};
