// @Title: Rotate Image
// @Author: colinjxc
// @Date: 2022-01-22T21:37:30+08:00
// @URL: https://leetcode-cn.com/problems/rotate-image


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        // assert(rowSize, colSize);

        for (int i = 0; i < rowSize / 2; i++) {
            for (int j = 0; j < colSize; j++) {
                std::swap(matrix[i][j], matrix[rowSize - i - 1][j]);
            }
        }

        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < i; j++) {
                if (i != j)
                    std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
