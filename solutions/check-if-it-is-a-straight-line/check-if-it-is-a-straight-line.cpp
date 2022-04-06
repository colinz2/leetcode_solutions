// @Title: Check If It Is a Straight Line
// @Author: colinjxc
// @Date: 2022-01-28T20:47:27+08:00
// @URL: https://leetcode-cn.com/problems/check-if-it-is-a-straight-line


class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // (y-y1)/(x-x1) = (y-y2)/(x-x2)
        // (y-y1)*(x-x2) = (y-y2)*(x-x1)
        int x = coordinates[0][0];
        int y = coordinates[0][1];
        for (int i = 1; i < coordinates.size(); i++) {
            int f1 = (y - coordinates[i-1][1]) * (x - coordinates[i][0]);
            int f2 = (y - coordinates[i][1]) * (x - coordinates[i-1][0]);
            if (f1 != f2) return false;
        }
        return true;
    }
};
