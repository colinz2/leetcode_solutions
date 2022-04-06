// @Title: Multiply Strings
// @Author: colinjxc
// @Date: 2019-01-01T12:32:23+08:00
// @URL: https://leetcode-cn.com/problems/multiply-strings


class Solution {
public:

    string reverse_str(string num) {
        string res = num;
        if (num.size() == 0) return res;
        int l = 0, r = num.size() - 1;
        while (l < r) {
            swap(res[l++], res[r--]);
        }
        return res;
    }

    string multiply(string num1, string num2) {
        //mul1是乘法式子中上面的数字，mul2是下面的。
        string mul1 = reverse_str(num1), mul2 = reverse_str(num2);
        if (mul2.size() > mul1.size()) {
            mul1 = mul2;
            mul2 = reverse_str(num1);
        }
        //vector<int> res(0, mul1.size() + mul2.size());
        vector<int> res;

        for (int i = 0; i < mul2.size(); i++) {
            int n2 = mul2[i] - 0x30;
            int carry = 0;
            for (int j = 0; j < mul1.size(); j++) {
                if (i + j >= res.size()) res.push_back(0);
                int n1 = mul1[j] - 0x30;
                int mul_n = (n1 * n2 + carry + res[i + j]) % 10;
                carry = (n1 * n2 + carry + res[i + j]) / 10;
                res[i + j] = mul_n;
            }
            if (carry) {
                res.push_back(carry);
            }
        }

        string s;
        auto it = res.rbegin();
        for (; it != res.rend(); it++) {
            if (*it != 0) break;
        }
        for (auto it_skip_zero = it; it_skip_zero != res.rend(); it_skip_zero++) {
            s += to_string(*it_skip_zero);
        }
        if (s.size() == 0) return "0";
        return s;
    }
};
