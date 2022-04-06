// @Title: Plus One
// @Author: colinjxc
// @Date: 2018-10-16T00:12:11+08:00
// @URL: https://leetcode-cn.com/problems/plus-one


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = false;
        for (auto i = digits.size(); i > 0; i--) {
            digits[i - 1] += 1;
            if (digits[i - 1] == 10) {
                digits[i - 1] = 0;
                carry = true;
            } else {
                carry = false;
                break;
            }
        }
        
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
