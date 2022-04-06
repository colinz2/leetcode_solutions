// @Title: Add Strings
// @Author: colinjxc
// @Date: 2018-12-06T17:11:41+08:00
// @URL: https://leetcode-cn.com/problems/add-strings


class Solution {
public:
    string addStrings(string num1, string num2) {
        string base = num2, adder = num1;
        int carry = 0;
        if (num1.size() > num2.size()) {
            base = num1;
            adder = num2;
        }
        for (int i = base.size() - 1, j = adder.size() - 1 ; i >= 0; i--, j--) {
            int sum = 0;
            if (j >= 0) {
                sum = (base[i] - 0x30) + (adder[j] - 0x30) + carry;
            } else {
                sum = base[i] - 0x30 + carry;
            }
            base[i] = (sum % 10) + 0x30;
            carry = sum / 10;
        }

        if (carry) {
            base.insert(base.begin(), '1');
        }
        return base;
    }
};

