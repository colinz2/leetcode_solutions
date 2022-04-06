// @Title: Transpose Matrix
// @Author: colinjxc
// @Date: 2018-11-23T18:26:26+08:00
// @URL: https://leetcode-cn.com/problems/transpose-matrix


class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int row_num = A.size();
        int col_num = A[0].size();
        vector<vector<int>> T(col_num);

        for (int i = 0; i < row_num; i++) {
            for (int j = 0; j < col_num; j++) {
                T[j].push_back(A[i][j]);
            }
        }
        return T;
    }
};
