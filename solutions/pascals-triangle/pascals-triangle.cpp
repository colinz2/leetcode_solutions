// @Title: Pascal's Triangle
// @Author: colinjxc
// @Date: 2018-10-15T22:33:14+08:00
// @URL: https://leetcode-cn.com/problems/pascals-triangle


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> yh_matrics;
        
        for (int i = 0; i < numRows; i++) {
            //初始化，全1.第一行，为1个
            vector<int> row(i + 1, 1);
            yh_matrics.push_back(row);
        }
        if (numRows > 2) {
            for (int i = 2; i < numRows; i++) {
                for (int j = 1; j < i; j++) {
                    //观察规律
                    yh_matrics[i][j] = yh_matrics[i-1][j-1] + yh_matrics[i-1][j];
                }
            }
        }
        
        return yh_matrics;
    }
};
