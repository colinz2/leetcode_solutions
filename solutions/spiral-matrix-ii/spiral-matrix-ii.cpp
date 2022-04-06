// @Title: Spiral Matrix II
// @Author: colinjxc
// @Date: 2022-02-09T15:53:38+08:00
// @URL: https://leetcode-cn.com/problems/spiral-matrix-ii


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        vector<vector<int>> directions = {{0, 1}, {1,0}, {0, -1}, {-1, 0}};
        int curr = 1, total = n*n;

        int i = 0, j = 0;
        int directionIndex = 0;
        while (curr <= total) {
            res[i][j] = curr++;
    
            int x = i + directions[directionIndex][0];
            int y = j + directions[directionIndex][1];
            if ((x == n ^ x < 0) || (y == n ^ y < 0) || res[x][y] != 0) {
                directionIndex = ++directionIndex % 4;
            }
            i += directions[directionIndex][0];
            j += directions[directionIndex][1];
        }

        return res;
    }
};
