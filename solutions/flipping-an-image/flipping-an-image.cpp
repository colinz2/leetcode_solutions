// @Title: Flipping an Image
// @Author: colinjxc
// @Date: 2018-10-15T17:25:07+08:00
// @URL: https://leetcode-cn.com/problems/flipping-an-image


class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {            
        for (auto &row : A) {
            int row_len = row.size();
            for (int i = 0; i < row_len / 2; i++) {
                int t = 1 - row[i];
                row[i] = 1 - row[row_len -1 - i];
                row[row_len -1 - i] = t;
            }
            if (row_len & 1) {
                row[row_len / 2] = 1 -  row[row_len / 2];
            }
        }
        return A;
    }
    
    
};
