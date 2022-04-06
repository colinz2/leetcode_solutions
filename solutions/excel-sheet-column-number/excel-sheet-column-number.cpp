// @Title: Excel Sheet Column Number
// @Author: colinjxc
// @Date: 2022-02-08T00:07:28+08:00
// @URL: https://leetcode-cn.com/problems/excel-sheet-column-number


class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0;
        for (auto c : columnTitle) {
            if (sum >= (INT_MAX - (c-'A'+1)) / 26) {
                return INT_MAX;
            }
            sum = ('Z'-'A' + 1) * sum + c - 'A' + 1;
        }
        return sum;
    }
};
