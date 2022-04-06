// @Title: Add Binary
// @Author: colinjxc
// @Date: 2018-11-28T15:51:12+08:00
// @URL: https://leetcode-cn.com/problems/add-binary


class Solution {
public:
    string addBinary(string a, string b) {
        string base , adder;
        if (a.size() > b.size()) {
            base = a;
            adder = b;
        } else {
            base = b;
            adder = a;
        }

        int carry = 0;
        for (int i = base.size() - 1, j = adder.size() - 1 ; i >= 0; i--, j--) {
            int sum = 0;
            if (j >= 0) {
               sum = (base[i] - 0x30) + (adder[j] - 0x30) + carry;
            } else {
                sum = base[i] - 0x30 + carry;
            }
            base[i] = (sum % 2) + 0x30;
            carry = sum / 2;
        }

        if (carry) {
            base.insert(base.begin(), '1');
        }

        return base;
    }
};
