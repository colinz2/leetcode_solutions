// @Title: Search a 2D Matrix
// @Author: colinjxc
// @Date: 2022-02-02T21:17:02+08:00
// @URL: https://leetcode-cn.com/problems/search-a-2d-matrix


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // select raw
        int j = 0, k = matrix.size() - 1;
        while (j <= k) {
            int m = (j+k) >> 1;
            if (matrix[m].front() > target) {
                k = m - 1;
            } else if (matrix[m].back() < target) {
                j = m + 1;
            } else {
                int i = 0, h = matrix[m].size();
                while (i < h) {
                    int mm = (i+h) >> 1;
                    if (matrix[m][mm] < target) {
                        i = mm + 1;
                    } else if (matrix[m][mm] > target) {
                        h = mm;
                    } else {
                        return true;
                    }
                }
                break;
            }
        }
        return false;
    }
};
