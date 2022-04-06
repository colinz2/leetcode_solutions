
# [字符串相乘](https://leetcode-cn.com/problems/multiply-strings)

## 题目描述

<p>给定两个以字符串形式表示的非负整数&nbsp;<code>num1</code>&nbsp;和&nbsp;<code>num2</code>，返回&nbsp;<code>num1</code>&nbsp;和&nbsp;<code>num2</code>&nbsp;的乘积，它们的乘积也表示为字符串形式。</p>

<p><strong>注意：</strong>不能使用任何内置的 BigInteger 库或直接将输入转换为整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> num1 = "2", num2 = "3"
<strong>输出:</strong> "6"</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> num1 = "123", num2 = "456"
<strong>输出:</strong> "56088"</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num1.length, num2.length &lt;= 200</code></li>
	<li><code>num1</code>&nbsp;和 <code>num2</code>&nbsp;只能由数字组成。</li>
	<li><code>num1</code>&nbsp;和 <code>num2</code>&nbsp;都不包含任何前导零，除了数字0本身。</li>
</ul>


## 题解

### cpp [🔗](multiply-strings.cpp) 
```cpp
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
```


## 相关话题

- [数学](https://leetcode-cn.com/tag/math) 
- [字符串](https://leetcode-cn.com/tag/string) 
- [模拟](https://leetcode-cn.com/tag/simulation) 


## 相似题目

- [两数相加](../add-two-numbers/README.md)  [Medium] 
- [加一](../plus-one/README.md)  [Easy] 
- [二进制求和](../add-binary/README.md)  [Easy] 
- [字符串相加](../add-strings/README.md)  [Easy] 


## Links

- [Prev](../trapping-rain-water/README.md) 
- [Next](../wildcard-matching/README.md) 

