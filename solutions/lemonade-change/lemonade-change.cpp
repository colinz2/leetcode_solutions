// @Title: Lemonade Change
// @Author: colinjxc
// @Date: 2022-01-28T00:38:44+08:00
// @URL: https://leetcode-cn.com/problems/lemonade-change


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5 = 0, cnt10 = 0;
        for (auto& bill : bills) {
            switch (bill) {
                case 5:
                    cnt5++;
                    break;
                case 10:
                    cnt10++;
                    if (cnt5 > 0) cnt5--;
                    else return false;
                    break;
                case 20:
                    if (cnt10 > 0) {
                        cnt10--;
                        if (cnt5 >= 1) cnt5--;
                        else return false;
                    } else {
                        if (cnt5 >=3 ) cnt5 -= 3;
                        else return false;
                    }
                    break;
                default:
                    return false;
            }
        }
        return true;
    }
};
